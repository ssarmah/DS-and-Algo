#include<stdio.h>
#include<string.h>

void strrev1(char*p)
{
    int i;
	char q[100];
	int l= (int) strlen(p),j=0;
	for(i= l-1;i>=0;i--)
		q[j++]=p[i];
	q[j]='\0';
	strcpy(p,q);
}

void DtoB(int n,char*binary)
{
    int i=0;
    while(n>0)
    {
        binary[i]=n%2+48;
        n=n/2;
        i++;
    }
    binary[i]='\0';
    strrev1(binary);
}

int no_of_one(char*p)
{
    int i;
    int count=0;
	for(i=0;i<strlen(p);i++)
    {
		if(p[i]=='1')
        	count++;
    }
    return count;
}

int main()
{
    int a,k,i;
    int n1,n2,len1,len2;
    char c1[100],c2[100];

    printf("Enter a Number                   : ");
    scanf("%d",&a);

    DtoB(a,c1);
    n1 = no_of_one(c1);


    printf("Length of a Binary string is     : %d\n",(int)strlen(c1));
    printf("Binary of a given Number is      : %s\n",c1);
    printf("Number of 1's in original string : %d\n",n1);
    len1 = strlen(c1);

    int flag=0;
    for(i=len1-1;i>0;i--){
		if(c1[i]=='1' && c1[i-1]=='0'){
			c1[i]='0';
			c1[i-1]='1';
			flag=1;
			break;
		}
	}

    if(flag==0 && i==0 && c1[0]=='1'){
    	c2[0]='1';
    	c2[1]='0';
		for(k=1;k<len1;k++)
			c2[k+1]=c1[k];
		c2[k+1]='\0';
		strcpy(c1,c2);
	}


	n2 = no_of_one(c1);


	printf("Number of 1's in next string : %d\n",n2);


	printf("Next string is: %s\n",c1);

	len2 = strlen(c1);


	if(len2 == len1)
		printf("Final output: %s\n\n",c1);
	else
		printf("Resultant string is not valid since it has different length and hence out of boundary \n\n");

	return 0;
}
