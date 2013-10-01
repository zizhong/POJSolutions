#include<stdio.h>
int a[10001];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
main()
{
      int n,i;
      scanf("%d",&n);
      for(i=0;i<n;i++)
         scanf("%d",&a[i]);
      qsort(a,n,sizeof(a[0]),cmp);
      printf("%d\n",a[(n-1)/2]);}
