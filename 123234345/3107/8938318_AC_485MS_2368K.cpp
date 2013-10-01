#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N=50010,M=10*N,inf=0x3fffffff;
int g[N],e[M],nxt[M],cnt;
int ans,st[N],top;
int after[N];
int n;
void addedge(int u,int v)
{
     e[cnt]=v;
     nxt[cnt]=g[u];
     g[u]=cnt++;
}
void dfs(int x,int pre)
{
     
     after[x]=1;
     int max=inf;
     /*for(int i=0;i<tree[x].size();i++) if(tree[x][i]!=pre)
     {
           dfs(tree[x][i],x);
           after[x]+=after[tree[x][i]];
           if(max==inf) max=after[tree[x][i]];
           else if(max<after[tree[x][i]]) max=after[tree[x][i]]; 
     }*/
     for(int p=g[x];p!=-1;p=nxt[p])if(e[p]!=pre)
     {
           dfs(e[p],x);
           after[x]+=after[e[p]];
           if(max==inf) max=after[e[p]];
           else if(max<after[e[p]]) max=after[e[p]];
     }
     if(max==inf) max=n-1;
     else max=n-after[x]>max?n-after[x]:max;
     if(ans==max)
     {
          st[top++]=x;
     }else if(ans>max)
     {
           ans=max;
           top=0;
           st[top++]=x;
     }
}
int main()
{
    memset(g,-1,sizeof(g));
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         addedge(a-1,b-1);
         addedge(b-1,a-1);
    }
    ans=inf;
    dfs(0,0);
    sort(st,st+top);
    for(int i=0;i<top;i++) printf("%d%c",st[i]+1,i==top-1?'\n':' ');
   // scanf("%'d");
}
