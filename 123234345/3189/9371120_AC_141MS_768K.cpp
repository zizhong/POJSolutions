#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1200+200+2;
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
bool bfs(int n,int s,int t)//ÕÒÔö¹ã 
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
                if(u!=t&&cur[u]&&cur[u]->flow>0&&d[u]+1==d[cur[u]->v])
                     {v=cur[u]->v;st[++top]=v;pre[v]=cur[u];u=v;}
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
int n,b;
int cap[21],prefer[1024][21];
bool solve(int l,int r)
{
     init();
     int s=0,t=n+b+1;
     for(int i=1;i<=n;i++)
         insert(s,i,1);
     for(int i=1;i<=n;i++)
         for(int j=l;j<=r;j++)
            insert(i,n+prefer[i][j],1);
     for(int i=1;i<=b;i++)
         insert(n+i,t,cap[i]);
     return dinic(t+1,s,t) == n;
}
bool ok(int range)
{
     for(int l=1;l+range-1<=b;l++)
     {
          if(solve(l,l+range-1)) return true;
     }
     return false;
}
int main()
{
    scanf("%d%d",&n,&b);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=b;j++)
           scanf("%d",&prefer[i][j]);
    for(int i=1;i<=b;i++)
         scanf("%d",&cap[i]);
    for(int ans=1;ans<=b;ans++)
    {
         if(ok(ans))
         {
               printf("%d\n",ans);
               break;
         }
    }  
}
