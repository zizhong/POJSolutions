#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int M=500000,N=410,INF=0xffffff;
int min(int x,int y){return x<y?x:y;}

struct node
{
       int v,flow,cost;
       node *next,*rev();
};
node edge[M],*adj[N],*rec[N];
bool use[N];
int d[N],pre[N],q[10*M],len;
node *node::rev(){return edge+((this - edge)^1);}
inline void add(int u,int v,int flow,int cost)
{
       edge[len].v=v,edge[len].flow=flow,edge[len].cost=cost;
       edge[len].next=adj[u],adj[u]=&edge[len++];
}
inline void insert(int u,int v,int flow,int cost)
{
       add(u,v,flow,cost);
       add(v,u,0,-cost);
}
bool SPFA(int n,int s,int t)
{
    
     int u,v,i,head=0,tail=0;
     q[tail++]=s;
     node *p;
     for(i=0;i<n;i++) d[i]=INF,use[i]=0,pre[i]=-1;
     d[s]=0,use[s]=1;
     while(head<tail)
     {
          for(u=q[head++],use[u]=0,p=adj[u];p;p=p->next)
               if(p->flow>0 && d[u]+p->cost <d[p->v])
               {
                    d[p->v]= d[u]+p->cost;
                    pre[p->v]=u,rec[p->v]=p;
                    if(use[p->v]==0) q[tail++]=p->v,use[p->v]=1;
               }
          
     }
     return d[t]==INF;
}
int mcmf(int n,int s,int t)
{    
    int u,v,mincost=0,tmp;
    int maxf=0;
    while(!SPFA(n,s,t))
    {
         for(tmp=INF,v=t;v!=s;v=pre[v]) tmp=min(tmp,rec[v]->flow);
         maxf+=tmp;
         for(mincost+=tmp*d[t],v=t;v!=s;v=pre[v])
                 rec[v]->flow-=tmp,rec[v]->rev()->flow+=tmp;
    }
    return mincost;
}
struct EP
{
       int d,flag,f;
}ep[N];
int ww[N/2];
int nep;
int cmp(const void *a,const void *b)
{
    return ((EP *)a)->d - ((EP*)b)->d;    
}
int main()
{
    int T,s,t,n,k;
    scanf("%d",&T);
    while(T--)
    {
          scanf("%d%d",&n,&k);
          len=nep=0;
          for(int i=0;i<N;i++) adj[i]=NULL;
          for(int i=0;i<n;i++)
          {
                int a,b;
                scanf("%d%d%d",&a,&b,&ww[i]);
                ep[nep].d=a,ep[nep++].flag=i;
                ep[nep].d=b,ep[nep++].flag=i;
          }
          qsort(ep,nep,sizeof(ep[0]),cmp);
          int inv[N]={0};
          memset(inv,-1,sizeof(inv));
          int mark[N]={0};
          for(int i=1;i<nep;i++)
          {
                  if(ep[i].d==ep[i-1].d) mark[i]=mark[i-1];
                  else mark[i]=i;
          }
          for(int i=0;i<nep;i++)
          {
                  int j=ep[i].flag;
                  if(inv[j]==-1) inv[j]=mark[i];
                  else insert(inv[j],mark[i],1,-ww[j]);
                  if(i&&mark[i-1]!=mark[i]) insert(mark[i-1],mark[i],k,0);
          }
          s=nep,t=s+1;
          insert(s,0,k,0);
          insert(mark[nep-1],t,k,0);
          printf("%d\n",-mcmf(t+1,s,t));
    }
}
