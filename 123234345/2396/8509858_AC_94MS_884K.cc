#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn=220+220+2;
const int maxm=(5000*3+5000)*2;
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
void init()
{
     for(int i=0;i<maxn;i++) adj[i]=NULL;
     len=0;
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
int n,m,s,t;
int in[maxn],out[maxn];
const int N=410,M=21;
int low[N][M],cap[N][M],flag;
void insert_low(int x,int y,int w)
{
     if(low[x][y]<w) low[x][y]=w;
     if(low[x][y]>cap[x][y]) flag=1;
}
void insert_cap(int x,int y,int w)
{
     if(cap[x][y]>w) cap[x][y]=w;
     if(cap[x][y]<low[x][y]) flag=1;
}
void slove()
{
     init();
     memset(in,0,sizeof(in));
     memset(out,0,sizeof(out));
     memset(low,0,sizeof(low));
     for(int i=0;i<N;i++)
          for(int j=0;j<M;j++)
               cap[i][j]=INF;
     flag=0;
     for(int i=1;i<=n;i++)
     {
          scanf("%d",&low[i][0]);
          cap[i][0]=low[i][0];
     }
     for(int i=1;i<=m;i++)
     {
          scanf("%d",&low[0][i]);
          cap[0][i]=low[0][i];
     }
     int c;
     scanf("%d",&c);
     for(int i=0;i<c;i++)
     {
         char r[2];
         int x,y,w;
         scanf("%d%d%s%d",&x,&y,r,&w);
         if(flag==1) continue;
         if(x&&y)
         {
              switch(r[0])
              {
                   case '>':insert_low(x,y,w+1);break;
                   case '<':insert_cap(x,y,w-1);break;
                   case '=':insert_low(x,y,w),
                            insert_cap(x,y,w);break;
              }
         }else
         if(x+y)
         {
                if(x==0)
                for(int i=1;i<=n;i++)
                {
                     switch(r[0])
                     {
                          case '>': insert_low(i,y,w+1);break;
                          case '<': insert_cap(i,y,w-1);break;
                          case '=': insert_low(i,y,w),
                                    insert_cap(i,y,w);break;
                     }
                }
                if(y==0)
                for(int i=1;i<=m;i++)
                {
                     switch(r[0])
                     {
                          case '>': insert_low(x,i,w+1);break;
                          case '<': insert_cap(x,i,w-1);break;
                          case '=': insert_low(x,i,w),
                                    insert_cap(x,i,w);break;
                     }
                }
         }else
         {
              for(int i=1;i<=n;i++)
                  for(int j=1;j<=m;j++)
                  {
                       switch(r[0])
                       {
                          case '>': insert_low(i,j,w+1);break;
                          case '<': insert_cap(i,j,w-1);break;
                          case '=': insert_low(i,j,w),
                                    insert_cap(i,j,w);break;
                       }   
                  }
         }
     }
     if(flag) return ;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cap[i][0]-=low[i][j];
            cap[0][j]-=low[i][j];
            if(cap[i][0]<0||cap[0][j]<0) flag=1;
        }
     int sr=0,sc=0,ss=0;
     for(int i=1;i<=n;i++) sr+=cap[i][0];
     for(int i=1;i<=m;i++) sc+=cap[0][i];
     if(sr!=sc) flag=1;
     if(flag) return ;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           insert(i,n+j,cap[i][j]-low[i][j]);
     for(int i=1;i<=n;i++) insert(0,i,cap[i][0]);
     for(int i=1;i<=m;i++) insert(n+i,n+m+1,cap[0][i]);
     s=0,t=n+m+1;
     ss=dinic(t+1,s,t);
     if(ss!=sc) flag=1;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d%d",&n,&m);
         slove();
         if(flag==1) puts("IMPOSSIBLE");
         else
         {
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                   printf("%d%c",low[i][j]+edge[2*((i-1)*m+j-1)+1].flow,j==m?'\n':' ');
         }
         if(T) puts("");
    }
}
