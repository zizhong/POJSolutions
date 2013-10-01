#include<stdio.h>
#include<string.h>
const int N=50001;
const __int64 inf =((__int64)1)<<61;
struct Node
{
       int v,w;
       Node *next;
}node[N*2],*e[N];
int n,m,cnt;
void insert(int u,int v,int w)
{
     Node *p=&node[cnt++];
     p->v=v;
     p->w=w;
     p->next=e[u];
     e[u]=p;
}
int q[N*100],head,tail;
int w[N];
__int64 d[N];
void SPFA()
{
     head=tail=0;
     for(int i=1;i<=n;i++)
         d[i]=inf;
     q[tail++]=1;
     d[1]=0;
     while(head<tail)
     {
          int cur=q[head++];
          for(Node *p=e[cur];p;p=p->next)
              if(d[p->v]>d[cur]+p->w)
              {
                   d[p->v]=d[cur]+p->w;
                   q[tail++]=p->v;
              }
     }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        cnt=0;
        for(int i=1;i<=n;i++)
        {
              scanf("%d",&w[i]);
              e[i]=NULL;
        }
        for(int i=1;i<=m;i++)
        {
             int u,v,wi;
             scanf("%d%d%d",&u,&v,&wi);
             insert(u,v,wi);
             insert(v,u,wi);
        }
        SPFA();
        /*for(int i=1;i<=n;i++)
           printf("%I64d ",d[i]);
        puts("");*/
        int flag=0;
        __int64 ans=0;
        for(int i=1;i<=n;i++)
        {
            if(d[i]==inf) flag=1;
            ans+=d[i]*w[i];
        }
        if(flag) puts("No Answer");
        else printf("%I64d\n",ans);
    }
}
