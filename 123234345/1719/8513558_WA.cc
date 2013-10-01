#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
const int maxn=1000+1000+2;
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
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int r,c;
         scanf("%d%d",&r,&c);
         init();
         int s=0,t=r+c+1;
         for(int i=1;i<=c;i++)
         {
              int r1,r2;
              scanf("%d%d",&r1,&r2);
              insert(i,r1+c,1);
              insert(i,r2+c,1);
         }
         for(int i=1;i<=c;i++)
              insert(0,i,1);
         for(int i=1;i<=c;i++)
             insert(r+i,t,1);
         int ans=dinic(t+1,s,t);
         if(ans!=r) puts("NO");
         else
         {
             int f1=0;
             for(int i=0;i<c;i++)
             {
                  int idx=i*4+1,idx1=i*4+3;
                  //puts("\n---");
                  if(edge[idx].flow)
                  {
                      if(f1) putchar(' ');f1=1;
                      printf("%d",edge[idx-1].v-c);
                  }
                  else if(edge[idx1].flow)
                  {
                      if(f1) putchar(' ');f1=1;
                      printf("%d",edge[idx1-1].v-c);
                  }
                  else
                  {
                      if(f1) putchar(' ');f1=1;
                      printf("%d",edge[idx-1].v-c);
                  }
             }
             puts("");
         }
    }
}
