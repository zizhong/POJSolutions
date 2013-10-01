#include<stdio.h>
int main()
{
    int n,a[31];
    while(scanf("%d",&n)&&n)
    {
        int i,sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i]; 
        }
        if(sum%2==0)
            sum/=2;
        else
        {
            printf("No equal partitioning.\n");
            continue;
        }
        for(i=1;i<=n;i++)
        {
            sum-=a[i];
            if(sum==0)
            {
               printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
               break;
            }
            if(sum<0)
            {               
               printf("No equal partitioning.\n");
               break;
            }
        }
    }
}
