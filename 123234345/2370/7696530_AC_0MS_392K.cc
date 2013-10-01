#include<stdio.h>
#include<stdlib.h>
const int N=102;
int d[N];
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    qsort(d+1,n,sizeof(d[0]),cmp);
    int sum=0;
    for(int i=1;i<=n/2+1;i++) sum+=d[i]/2+1;
    printf("%d\n",sum);
}
