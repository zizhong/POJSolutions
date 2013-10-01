#include<stdio.h>
#include<string.h>
const int N=5010,M=20010,mod=25327;
bool map[N][N];
int h[N],to[M],next[M],cnt;
int dfn[N],low[N],ntime;
int n,m;
int min(int a,int b){return a>b?b:a;}
void add(int u,int v)
{
     map[u][v]=1;
     to[cnt]=v,next[cnt]=h[u];
     h[u]=cnt++;
}
int num;
int tarjan(int u,int v)
{
    int i,s=0;
    dfn[u]=low[u]=++ntime;
    for(i=h[u];i!=-1;i=next[i])
        if(!dfn[to[i]])
        {
             int t=tarjan(to[i],u);
             low[u]=min(low[u],low[to[i]]);
             if(low[to[i]]>dfn[u])
                 num+=!t,s++;
             else s+=t;
        }else if(to[i]!=v && dfn[to[i]]<dfn[u]) low[u]=min(low[u],dfn[to[i]]);
   return s;     
}
int main()
{
    memset(h,-1,sizeof(h));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(!map[u][v]) add(u,v),add(v,u);
    }
    num+=(tarjan(1,-1)==1);
    printf("%d\n",(num+1)>>1);
}
