#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void* b)
{
     return *(int *)a-*(int *)b;
}
int main()
{
    int n,i,j,a[100005],count,c=0,l;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    count=n,j=0;
    for(i=n-1;i>j;i--)
        if(a[i]+a[j]<=l) j++,count--;
    printf("%d\n",count);
}