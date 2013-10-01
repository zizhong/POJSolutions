#include<stdio.h>
int a[51];
int accord(int a,int b)
{
    int i;
    for(i=2;i<=a&&i<=b;i++)
       if(a%i==0&&b%i==0) return 0;
    return 1;
}
main()
{
      int i,j,pair,n;
      while(scanf("%d",&n)&&n)
      {
         pair=0;
         for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
         for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
              if(accord(a[i],a[j])) pair++;
         if(pair) printf("%.6f\n",sqrt(3.0*n*(n-1)/(1.0*pair)));
         else printf("No estimate for this data set.\n");
      }
}
