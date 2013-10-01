#include<stdio.h>
double a[101];
int cmp(const void *a,const void *b)
{
    return *(double *)b>*(double *)a?1:-1;
}
main()
{
      int n,i;
      double sum;
      scanf("%d",&n);
      for(i=0;i<n;i++)
         scanf("%lf",&a[i]);
      qsort(a,n,sizeof(a[0]),cmp);
      for(i=1;i<n;i++)
          a[i]=2*sqrt(a[i-1]*a[i]);
      printf("%.3lf\n",a[n-1]);
}
