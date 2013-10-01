#include<stdio.h>
int a[16];
main()
{
      int i=0;
      while(scanf("%d",&a[i++])&&a[0]!=-1)
      {
         int j,k,n=0;
         while(scanf("%d",&a[i++])&&a[i-1]);
         for(j=0;j<i-1;j++)
            for(k=0;k<i-1;k++)
            if(2*a[j]==a[k]) n++;
         printf("%d\n",n);
         i=0;
      }
}
