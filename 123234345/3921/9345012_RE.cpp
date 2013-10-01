#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=200+200+2;
const int maxm=(40000*3+40000)*2;
const int INF=100000000;
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
bool bfs(int n,int s,int t)//0100·390100·360100·380106§820106¥910100”70 
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
const int inf=0x3fffffff;
int g[60][60];
int n,m,k;
int dist[60][60];
void floyd()
{
     memcpy(dist,g,sizeof(g));
     for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++) if(dist[i][k]==inf)
             for(int j=1;j<=n;j++) if(dist[k][j]==inf && dist[i][j]>dist[i][k]+dist[k][j])
                 dist[i][j]=dist[i][k]+dist[k][j];
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k),n)
    {
          for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                  if(i!=j) g[i][j]=inf;
          for(int i=1;i<=m;i++)
          {
               int u,v;
               scanf("%d%d",&u,&v);
               if(u!=v) g[u][v]=1;
          }
          floyd();
          init();
          //for(int i=1;i<=n;i++)
          //    insert(i-1,i+n-1,1);
          int in[60]={0};
          for(int i=1;i<=n;i++)
              for(int j=1;j<=m;j++)
                  if(g[i][j]==1 && dist[1][i]+dist[j][n]+1 <= k && i!=j)
                  {
                         insert(n+i-1,j-1,INF),insert(n+j-1,i-1,INF);
                         if(in[i]==0) in[i]=1,insert(i-1,i+n-1,1);
                         if(in[j]==0) in[j]=1,insert(j-1,j+n-1,1);
                  }
          int s=n+1-1,t=n-1;
          printf("%d\n",dinic(2*n,s,t));
    }
}
