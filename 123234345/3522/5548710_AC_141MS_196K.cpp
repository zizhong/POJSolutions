#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Edge
{
     int i,
         j,
         w;
}e[5000];
int n,m;
int pre[101];
bool mark[5000];
int cmp(const void *a,const void *b)
{
    Edge *c=(Edge *)a;
    Edge *d=(Edge *)b;
    return c->w - d->w;
}
int Find(int i)
{
     int r=i;
     while(pre[r]>0) r=pre[r];
     while(r!=i) {int t=pre[i];pre[i]=r;i=t;}
     return r;
}
void Union(int a,int b)
{
     int t1=Find(a),t2=Find(b),
         temp=pre[t1]+pre[t2];
     if(pre[t1]<pre[t2]) pre[t2]=t1,pre[t1]=temp;
     else pre[t1]=t2,pre[t2]=temp;
}
int CNT()
{
    int x=Find(1);
    for(int i=2;i<=n;i++)
        if(x!=Find(i)) return 0;
    return 1;
}
int slimness(int i)
{
    int j;
    memset(pre,-1,sizeof(pre));
    memset(mark,false,sizeof(mark));
    int count=0;
    for(j=i;j<m&&count<n-1;j++)
       if(Find(e[j].i)!=Find(e[j].j)) Union(e[j].i,e[j].j),mark[j]=true,count++;
    if(!CNT()) return -1;
    for(j=m-1;!mark[j];j--) ;
    return e[j].w-e[i].w;
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
         int i,j,k;
         for(i=0;i<m;i++)
             scanf("%d%d%d",&e[i].i,&e[i].j,&e[i].w);
         
         qsort(e,m,sizeof(e[0]),cmp);
         int slim=99999999;
         for(i=0;i<m;i++)
         {
             int t=slimness(i);
             if(t==-1) break;
             if(t<slim) slim=t;
         }
         if(slim==99999999) printf("-1\n");
         else printf("%d\n",slim);
    }
}
