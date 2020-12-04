#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void ganttchart(int gantt[],int from,int to,int process)
{
    int i;
    for(i=from;i<=to;i++)
        gantt[i] = process;
}

void rearrange(int pq[],int n,int running_processes)
{
    int i;
    int temp = pq[0];
    for(i=0;i<running_processes;i++)
    {
        pq[i] = pq[i+1];
    }
    pq[running_processes-1] = temp;
}
int main()
{
  int noj=0
  int count,i,j;
  int time_quantum,n;
  int time = 0;
  int t_check =0;
  //printf("enter no of processes and time quantum");
  //scanf("%d\n%d" ,&n,&time_quantum);


  if(n <= 0 || time_quantum <= 0)
  {
      printf("Invalid data!");
      return 0;
  }
  printf("The number of processes are set to: %d\nThe time quantum is set to:%d\n" , n,time_quantum);

  int at[10],bt[10],rt[10],pq[10],pflag[10],tat[10];

  for(j=0;j<n;j++)
  {
      pq[j] = 0;
      pflag[j] = 0;
  }

  printf("The scanned process data is:\n\n");
  printf("--------------------------------------------------\n");
  printf("|\tINDEX\t|\tAT\t|\tBT\t|\n");
  for(count=0;count<n;count++)
  {
        printf("Enter Arrival Time and Execution Time for Process Number %d :",count+1);
        scanf("%d",&at[count]);
        scanf("%d",&bt[count]);

        printf("|\t%d\t|\t%d\t|\t%d\t|\n",count+1,at[count],bt[count]);
        rt[count]=bt[count];
        t_check += bt[count];

        if(at[count] < 0 || bt[count] <= 0)
        {
            printf("Invalid Data!");
            return 0;
        }
  }
  printf("--------------------------------------------------\n");

  int gantt[200];

  for(i=0;i<200;i++)
    gantt[i] = 0;

  int current = 0;
  printf("\nThe order of execution:\n\n");
  int running_processes = 0;

    pq[0] = 1;
    running_processes = 1;
    pflag[0] = 1;
    int flag = 0;

    while(running_processes!=0)
    {
            flag = 0;
            printf("Process queue: ");
            for(i=0;i<running_processes;i++)
                printf("%d ",pq[i]);
            printf("\t");
            printf("Remaining Time: ");
            for(i=0;i<n;i++)
                printf("%d ",rt[i]);
            printf("\tRunning processes: %d\n",running_processes);

            if(rt[pq[0]-1]>time_quantum)
            {
                rt[pq[0]-1] = rt[pq[0]-1] - time_quantum;
                time = time + time_quantum;
                printf("Process %d executed for %d bursts till time %d\n",pq[0],time_quantum,time);
                ganttchart(gantt,current,time,pq[0]);
                current = time;

            }

            else
            {
                time = time + rt[pq[0]-1];
                printf("Process %d executed for %d bursts till time %d\n",pq[0],rt[pq[0]-1],time);
                rt[pq[0]-1] = 0;
                flag = 1;
                ganttchart(gantt,current,time,pq[0]);
                current = time;
                tat[pq[0]-1] = time - at[pq[0]-1];
                printf("\n Status of current process=Completed \n");

            }

            for(i=0;i<n;i++)
            {
                if(at[i] <= time && pflag[i]== 0)
                {
                    pq[running_processes] = i+1;
                    running_processes = running_processes + 1;
                    pflag[i] = 1;
                }
            }

            rearrange(pq,n,running_processes);



            if(flag == 1)
                running_processes = running_processes - 1;

    }
   printf("\n\nFinal Execution Data:\n");
   printf("----------------------------------------------------------------------------------\n");
   printf("|\tProcess\t|\tAT\t|\tBT\t|\tFinish_time\t|\n");
   for(i=0;i<n;i++)
   {
       printf("|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\n",i+1,at[i],bt[i],tat[i]);
   }

   return 0;
}
