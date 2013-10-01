#include<stdio.h>
int a[1001];
main()
{
      int t,h;
      scanf("%d",&t);
      h=t;
      while(t--)
      {
         int n,i,j,q=0;
         scanf("%d",&n);
         for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
         for(i=1;i<n;i++)
           for(j=i+1;j<=n;j++)
             if(a[i]>a[j]) q++;
         printf("Scenario #%d:\n%d\n\n",h-t,q);
      }
}
