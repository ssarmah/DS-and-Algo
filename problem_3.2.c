#include<stdio.h>
#include<math.h>
int main()
{
    int h,x,i,n,y;

    int a[100];
    a[0]=1;
    a[1]=2;

    printf("\n enter height of BST");
    scanf("%d",&h);

    printf("\n enter no of nodes in BST");
    scanf("%d",&n);

    for(i=2;i<(h+1);i++)
    {
        a[i]=a[i-1]+a[i-2]+1;
        x=a[i];
    }
    printf("\n Minimum no of node is: %d\n",x);
    y=pow(2,(h+1))-1;
    printf("\n Maximum no of node is: %d\n",y);

    if(n>=x && n<=y)
    {
       printf("\n tree is AVL");
    }
    else
    {
        printf("\n tree is not AVL");
    }
return 0;

}
