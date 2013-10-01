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
    return c->w - d->w;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
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
    int marke[50000]={0},markp[20001]={0};
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<R;i++)
       if(Find(e[i].i)!=Find(e[i].j)) Union(e[i].i,e[i].j),marke[i]=markp[e[i].i]=markp[e[i].j]=1;
    int sum=0;
    for(int i=0;i<R;i++)
        if(marke[i]) sum+=e[i].w;
    int root[20001]={0};
    for(int i=1;i<=N+M;i++)
       root[i-1]=Find(i);
    qsort(root,N+M,sizeof(root[0]),cmp2);
    for(int i=1;i<=N+M;i++)
        if(root[i]!=root[i-1]) sum+=10000;
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
              e[i].w=10000-e[i].w;            
        }
        qsort(e,R,sizeof(e[0]),cmp);
        int mon=solve();
        printf("%d\n",mon);
    }
}

