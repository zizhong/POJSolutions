#include<stdio.h>
#include<string.h>
const int M=(50*50*3+30),N=50*50*2+10,INF=0xffffff;
int map[51][51];
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
    while(!SPFA(n,s,t))
    {
         for(tmp=INF,v=t;v!=s;v=pre[v]) tmp=min(tmp,rec[v]->flow);
         for(mincost+=tmp*d[t],v=t;v!=s;v=pre[v])
                 rec[v]->flow-=tmp,rec[v]->rev()->flow+=tmp;
    }
    return mincost;
}
int main()
{
    int n,s,k,t,f;
    while(scanf("%d%d",&n,&k)==2)
    {
          for(int i=0;i<n*n*2+2;i++) adj[i]=NULL;
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
                   scanf("%d",&map[i][j]);
          s=0,t=n*n*2-1,len=0;
          for(int i=0;i<n;i++)
              for(int j=0;j<n;j++)
              {
                   f=i*n+j;
                   insert(f*2,f*2+1,1,-map[i][j]);
              }
          for(int i=0;i<n;i++)
              for(int j=0;j<n-1;j++)
              {
                   f=i*n+j;
                   insert(f*2+1,f*2+2,1,0);
              }
          for(int i=0;i<n-1;i++)
              for(int j=0;j<n;j++)
              {
                   f=i*n+j;
                   insert(f*2+1,2*(f+n),1,0);
              }
          for(int i=1;i<=k;i++)
                   insert(s,s+1,1,0),insert(t-1,t,1,0);
          printf("%d\n",-mcmf(t+1,s,t));
    }
}
