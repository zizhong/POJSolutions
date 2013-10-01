#include<stdio.h>
const int N=20001;
struct Node
{
       int v;
       Node *next;
}e[N*2],*g[N];
int nn,cnt;
void addedge(int u,int v)
{
     Node *p=&e[nn++];
     p->v=v;
     p->next=g[u];
     g[u]=p;
}
void insert(int u,int v)
{
     addedge(u,v);
     addedge(v,u);
}
int size[N],v[N];
int dfs(int u)
{
    v[u]=cnt++;
    int ans=1;
    for(Node *p=g[u];p;p=p->next) if(!v[p->v])
    {
          ans+=dfs(p->v);
    }
    return size[u]=ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        nn=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
           g[i]=NULL,size[i]=v[i]=0;
        for(int i=0;i<n-1;i++)
        {
             int a,b;
             scanf("%d%d",&a,&b);
             insert(a,b);
        }
        cnt=1;
        dfs(1);
        int ans=n,mi;
        for(int i=1;i<=n;i++)
        {
             int max=0;
             for(Node *p=g[i];p;p=p->next) if(v[p->v]>v[i])
             {
                   if(max<size[p->v]) max=size[p->v];
             }
             if(max<size[1]-size[i]) max=size[1]-size[i];
             if(ans>max) ans=max,mi=i;
        }
        printf("%d %d\n",mi,ans);
    }
}
