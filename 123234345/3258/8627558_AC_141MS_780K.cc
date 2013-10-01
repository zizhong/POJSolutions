#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=50010;
int pos[N],L,v[N],n,m;
int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int ok(int x)
{
    memset(v,0,sizeof(v));
    v[0]=1;
    int num=0,pre=0;
    for(int i=1;i<=n;i++)
    {
        if(pos[i]-pos[pre]<x) num++;
        else v[i]=1,pre=i;
    }
    for(int i=n;i>0&&L-pos[i]<x;i--) if(v[i]) num++;
    return num <= m;
}
int main()
{
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&pos[i]);
    qsort(pos,n+1,sizeof(pos[0]),cmp);
    pos[n+1]=L;
    int l=0,r=L+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(ok(mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}
