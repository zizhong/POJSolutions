#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    while(n--)
    {
       int i,g[1001],sum=0;
       double ave,rad=0;
       scanf("%d",&m);
       for(i=1;i<=m;i++)
       {
          scanf("%d",&g[i]);
          sum+=g[i];
       }
       ave=sum*1.0/m;
       for(i=1;i<=m;i++)
         if(g[i]>ave) rad++;
       rad/=m;
       printf("%.3lf%%\n",100*rad);
    }
}
