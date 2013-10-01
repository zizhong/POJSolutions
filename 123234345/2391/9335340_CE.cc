#include<cstdio>
#include<iostream>
#include<iostream>
using namespace std;
#define  i64 __int64
const int maxn=400+400+2;
const int maxm=(40000*3+40000)*2;
const int INF=100000000;
const i64 inf = 1LL<<60;
inline int min(int x,int y){return x<y?x:y;}
int d[maxn],q[maxn],st[maxn],top,len;
typedef struct node
{
    int v,flow;
    node *next;
    node *rev();    
}node;
node edge[maxm],*adj[maxn],*cur[maxn],*pre[maxn];
node inline *node::rev(){return edge+((this-edge)^1);}
inline void addedge(int u,int v,int flow)
{
    edge[len].v=v;edge[len].flow=flow;
    edge[len].next=adj[u];adj[u]=&edge[len++]; 
}
inline void insert(int u,int v,int flow)
{
    addedge(u,v,flow);
    addedge(v,u,0); 
}
bool bfs(int n,int s,int t)
{
    int i,u,v,head=0,tail=0;q[tail++]=s;
    fill(d,d+n,-1);
    node *p;d[s]=0;
    while(head<tail)
    {
          for(u=q[head++],p=adj[u];p;p=p->next)
          {
              v=p->v;
              if(d[v]==-1&&p->flow>0)
              {
                 d[v]=d[u]+1;
                 q[tail++]=v;
                 if(v==t)return 1;                    
              }                                 
          }          
    } 
    return 0;      
} 
int dinic(int n,int s,int t) 
{
    int i,u,v,tmp,maxflow=0;
    while(bfs(n,s,t)) 
    {
          st[top=1]=u=s;
          for(i=0;i<n;i++)cur[i]=adj[i];
          while(cur[s])
          {
                if(u!=t&&cur[u]&&cur[u]->flow>0&&d[u]+1==d[cur[u]->v]){v=cur[u]->v;st[++top]=v;pre[v]=cur[u];u=v;}
                else if(u==t)
                {
                    for(tmp=INF,i=top;i>1;i--)tmp=min(tmp,pre[st[i]]->flow);
                    for(maxflow+=tmp,i=top;i>1;i--)
                    {
                        pre[st[i]]->flow-=tmp;
                        pre[st[i]]->rev()->flow+=tmp;
                        if(pre[st[i]]->flow==0)top=i-1;
                    }
                    u=st[top];  
                }
                else 
                {
                    while(u!=s&&cur[u]==NULL)u=st[--top];
                    cur[u]=cur[u]->next;
                }
          }
    }
    return maxflow;
}   
void init()
{
     for(int i=0;i<maxn;i++) adj[i]=NULL;
     len=0;
}
int n,m,cow[210],shelf[210],cowcnt,shelfcnt;
i64 g[210][210];
i64 road[201*200],cc;
void floyd_road()
{
     for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(g[i][k]<inf)
           for(int j=1;j<=n;j++) if(g[k][j]<inf)
                if(g[i][j]>g[i][k]+g[k][j])
                      g[i][j]=g[i][k]+g[k][j];
     cc=0;
     for(int i=1;i<=n;i++)
          for(int j=i+1;j<=n;j++) if(g[i][j]!=0 && g[i][j]!=inf)
              road[cc++]=g[i][j];
     sort(road,road+cc);
     int nn=cc;
     cc=0;
     for(int i=1;i<nn;i++)
         if(road[i-1]!=road[i])
             road[cc++]=road[i];
}
bool ok(i64 x)
{
     init();
     int s=0,t=2*n+1;
     for(int i=1;i<=n;i++)
     {
           insert(s,i,cow[i]);
           insert(i,i+n,INF);
           insert(i+n,t,shelf[i]);
     }
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j && g[i][j]<=x)
            insert(i,j+n,INF);
     int tmp=dinic(t+1,s,t);
     return tmp==cowcnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&cow[i],&shelf[i]);
        cowcnt+=cow[i];
        shelfcnt+=shelf[i];
    }
    for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
             if(i!=j) g[i][j]=inf;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        i64 w;
        scanf("%d%d%I64d",&u,&v,&w);
        if(g[u][v]>w) g[v][u]=g[u][v]=w;
    }
    floyd_road();
    if(cowcnt==0) puts("0");
    else if(cowcnt>shelfcnt) puts("-1");
    else
    {
        if(ok(0)) puts("0");
        else if(!ok(road[cc-1])) puts("-1");
        else
        {
            i64 ans=road[cc-1];
            int l=0,r=cc-1;
            while(l+1<r)
            {
                 int mid=l+r>>1;
                 if(ok(road[mid])) ans=road[mid],r=mid;
                 else l=mid;
            }
            printf("%I64d\n",ans);
        }
    }    
}
