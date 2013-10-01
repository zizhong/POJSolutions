#include<stdio.h>
#include<string.h>
const int N=2000,M=50;
struct Node
{
       int v,w;
       Node *next;
}g[M],e[2*N];
int cnt,st[N],top,v[N],d[M];
int min(int a,int b){return a<b?a:b;}
void addedge(int u,int v,int w)
{
     Node *p=&e[cnt++];
     p->v=v;
     p->w=w;
     p->next=g[u].next;
     g[u].next=p;
}
void insert(int u,int v,int w)
{
     addedge(u,v,w);
     addedge(v,u,w);
}
void init()
{
     cnt=top=0;
     memset(v,0,sizeof(v));
     memset(d,0,sizeof(d));
     for(int i=0;i<M;i++)
         g[i].next=NULL;
}
void eular(int x)
{
     for(Node *p=g[x].next;p;p=p->next)
     {
           if(v[p->w]) continue;
           
           v[p->w]=1;
           eular(p->v);
           st[top++]=p->w;
     }
}
int main()
{
    int u,v,w;
    while(scanf("%d%d",&u,&v),u)
    {
          init();
          int start=min(u,v);
          scanf("%d",&w);
          insert(u,v,w);
          d[u]++,d[v]++;
          while(scanf("%d%d",&u,&v),u)
          {
               scanf("%d",&w);
               insert(u,v,w);
               d[u]++,d[v]++;
          }
          int flag=0;
          for(int i=0;i<M;i++)
            if(d[i]&1) flag=1;
          if(flag) puts("Round trip does not exist.");
          else
          {
              eular(start);
              while(top) {top--;printf("%d%c",st[top],top?' ':'\n');}
          }
    }

}
