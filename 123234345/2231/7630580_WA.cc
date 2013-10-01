#include<stdio.h>
#include<stdlib.h>
const int N=10001;
int d[N];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
         scanf("%d",&d[i]);
    qsort(d,n,sizeof(d[0]),cmp);
    __int64 sum[N]={0};
    for(int i=n-1;i>=0;i--)
        sum[i]=d[i]+sum[i+1];
    __int64 ans=0;
    for(int i=0;i<n;i++)
    {
          ans+=sum[i+1]-(n-i-1)*d[i];
    }
    printf("%I64d\n",ans*2);
    scanf("%'d");
}
