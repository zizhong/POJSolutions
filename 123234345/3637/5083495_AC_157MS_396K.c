#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
   int price[20000];
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int sum=0,n,i;
      scanf("%d",&n);
      for(i=0;i<n;i++)
         scanf("%d",&price[i]);
      qsort(price,n,sizeof(price[0]),cmp);
      for(i=2;i<n;i+=3)
        sum+=price[i];
      printf("%d\n",sum);
   }
}
