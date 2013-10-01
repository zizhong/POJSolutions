#include<stdio.h>
const int MIN = -999999999;
main()
{
    int n,i,sum,ans,j;
    while(scanf("%d",&n),n)
    {
        int a[10001]={0},f[10001]={0};
        sum=0;j=MIN;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum=sum+a[i];
            if(j<sum) j=sum;            
            f[i]=j;
            if(sum<0) sum=0;
        }
        sum=0;ans=MIN;
        for(i=n;i>1;i--)
        {
           sum=sum+a[i];           
           ans=ans<f[i-1]+sum?f[i-1]+sum:ans; 
           if(sum<0) sum=0;
        }
        printf("%d\n",ans);
    }}
