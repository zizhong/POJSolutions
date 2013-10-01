#include<stdio.h>
main()
{
   int n;
   while(scanf("%d",&n)&&n!=-1)
   {
      int i,a[2][11]={0},r=0;
      for(i=1;i<=n;i++)
      {
         scanf("%d%d",&a[0][i],&a[1][i]);
         r+=a[0][i]*(a[1][i]-a[1][i-1]);
      }
      printf("%d miles\n",r);
   }
}
