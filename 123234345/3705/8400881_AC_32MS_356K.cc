#include<stdio.h>
int main()
{
    int n;
    /*while(*/scanf("%d",&n);/*==1){*/
    int k=n/2;
    if(n==1) puts("0");
    else if(n==2) printf("1\n2 1 0\n");
    else
    {
        printf("%d\n1 %d %d\n",k+1,k,n-k-1);
        for(int i=0;i<=n-k-2;i++)
           printf("%d %d %d\n",n-k-i+1,k,n-k-2-i);
        if(n%2==0) printf("%d %d %d\n",1,1,k);
    }
//}
}
