#include<stdio.h>
const int N=100001;
const __int64 inf=100000000*(__int64)100001;
int d[N],v[N];
__int64 num[N];
struct Node
{
       int v;
       Node *next;
}node[2*N],*e[N];
int cnt;
void addedge(int u,int v)
{
     Node *p=&node[cnt++];
     p->v=v;
     p->next=e[u];
     e[u]=p;
}
__int64 dfs(int u)
{
     v[u]=1;
     for(Node *p=e[u];p;p=p->next)
          if(v[p->v]==0)  num[u]+=dfs(p->v);
     return num[u];
}
__int64 _abs(__int64 a){return a>=(__int64)0?a:-a;}
int main()
{
    int n,m,T=0;
    while(scanf("%d%d",&n,&m),n)
    {
        for(int i=1;i<=n;i++)
            scanf("%I64d",&num[i]);
        cnt=0;
        for(int i=1;i<=n;i++)
           e[i]=NULL,v[i]=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1);
        __int64 min=inf;
        for(int i=1;i<=n;i++)
            if(_abs(num[1]-num[i]-num[i])<min)
               min=_abs(num[1]-num[i]-num[i]);
        printf("Case %d: %I64d\n",++T,min);
    }
}
