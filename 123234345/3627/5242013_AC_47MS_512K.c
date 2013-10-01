#include<stdio.h>
int h[20001];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int main()
{
   int n,b,i;
   scanf("%d%d",&n,&b);
   for(i=0;i<n;i++)
       scanf("%d",&h[i]);
   qsort(h,n,sizeof(h[0]),cmp);
   for(i=0;(b-=h[i])>0;i++) ;
   printf("%d\n",i+1);}
