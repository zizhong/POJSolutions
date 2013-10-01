#include<stdio.h>
int cow[20000];
int cmp(const void* a,const void *b)
{
    return *(int *)a-*(int *)b;
}
main()
{
      int n,s,i,r=0,j;
      scanf("%d%d",&n,&s);
      for(i=0;i<n;i++)
        scanf("%d",&cow[i]);
      qsort(cow,n,sizeof(cow[0]),cmp);
      for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
           if(cow[i]+cow[j]<=s) r++;
           else break;               
        }
      printf("%d\n",r);
}
