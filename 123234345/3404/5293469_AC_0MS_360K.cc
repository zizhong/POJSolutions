#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int min(int a,int b)
{
    if(a>b) return b;
    return a;
}
int a[50];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
    int i,r=0;
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=n-1;i>=3;i-=2)
      r+=min(a[i-1]+a[i]+2*a[0],2*a[1]+a[0]+a[i]);
    if(i==0) r+=a[0];
    if(i==1) r+=a[1];
    if(i==2) r+=a[2]+a[1]+a[0];
    printf("%d\n",r);
    }
}
