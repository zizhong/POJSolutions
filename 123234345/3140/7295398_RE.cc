#include<stdio.h>
const int N=100001;
const __int64 inf=100000000*100001;
int d[N],v[N];
__int64 num[N];
struct Node
{
       int v;
       Node *next;
}node[N],*e[N];
int cnt;
void addedge(int u,int v)
{
     Node *p=&node[cnt++];
     p->v=v;
     p->next=e[u];
     e[u]=p;
}
int dfs(int u)
{
     if(v[u]) return 0;
     v[u]=1;
     num[u]+=d[u];
     for(Node *p=e[u];p;p=p->next)
            num[u]+=dfs(p->v);
     return num[u];
}
__int64 abs(__int64 a){return a>(__int64)0?a:-a;}
int main()
{
    int n,m,T=0;
    while(scanf("%d%d",&n,&m),n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&d[i]);
        cnt=0;
        for(int i=1;i<=n;i++)
           e[i]=NULL,v[i]=0,num[i]=(__int64)0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs(1);
        __int64 min=inf;
        for(int i=2;i<=n;i++)
            if(abs(num[1]-num[i]-num[i])<min)
               min=abs(num[1]-num[i]-num[i]);
        /*for(int i=1;i<=n;i++)
             printf("%I64d ",num[i]);
        printf("\n");*/
        printf("Case %d: %I64d\n",++T,min);
    }
}
