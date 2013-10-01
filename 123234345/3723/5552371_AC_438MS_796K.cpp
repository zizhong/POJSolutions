#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pre[20001];
int N,M,R;
struct Edge
{
       int i,j,w;
}e[50001];
int cmp(const void *a,const void *b)
{
    Edge *c=(Edge*)a;
    Edge *d=(Edge*)b;
    return d->w - c->w;
}
int Find(int i)
{
    int r=i;
    while(pre[r]>=0) r=pre[r];
    while(r!=i){int t=pre[i];pre[i]=r;i=t;}
    return r;
}
void Union(int a,int b)
{
    int t1=Find(a),t2=Find(b),temp=pre[t1]+pre[t2];
    if(pre[t1]<pre[t2]) pre[t2]=t1,pre[t1]=temp;
    else pre[t1]=t2,pre[t2]=temp;
}
int solve()
{
    memset(pre,-1,sizeof(pre));
    int sum=0;
    int count=0;
    for(int i=0;i<R&&count<N+M-1;i++)
       if(Find(e[i].i)!=Find(e[i].j)) Union(e[i].i,e[i].j),sum+=e[i].w,count++;
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,k;
        memset(e,0,sizeof(e));
        scanf("%d%d%d",&N,&M,&R);
        for(i=0;i<R;i++)
        {
              scanf("%d%d%d",&e[i].i,&e[i].j,&e[i].w);
              e[i].j+=N+1;
              e[i].i+=1;
        }
        qsort(e,R,sizeof(e[0]),cmp);
        int mon=solve();
        printf("%d\n",(N+M)*10000-mon);
    }
}
