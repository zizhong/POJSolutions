#include<stdio.h>
#include<string.h>
const int N=105;
int g[N][N];
int n,m;
int Q[N],pre[N];
int max_flow(int s,int t)
{
    int p,q,u,v;
    int flow=0,aug;
    while(true)
    {
        memset(pre,-1,sizeof(pre));
        for(Q[p=q=0]=s;p<=q;p++)
        {
             u=Q[p];
             for(v=0;v<n+n&&pre[t]<0;v++)
                 if(g[u][v]>0&&pre[v]<0)
                     pre[v]=u,Q[++q]=v;
             if(pre[t]>=0) break;
        }
        if(pre[t]<0) break;
        aug=N;
        for(u=pre[v=t];v!=s;v=u,u=pre[u]) if(g[u][v]<aug) aug=g[u][v];
        for(u=pre[v=t];v!=s;v=u,u=pre[u])
              g[u][v]-=aug,g[v][u]+=aug;
        flow+=aug;
    }
    return flow;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
         int map[N][N]={0};
         while(m--)
         {
              int u,v;
              scanf(" (%d,%d)",&u,&v);
              map[n+u][v]=N;
              map[n+v][u]=N;
         }
         for(int i=0;i<n;i++) map[i][n+i]=1;
         int ans=n;
         for(int i=1;i<n;i++)
         {
             for(int x=0;x<n+n;x++)
                 for(int y=0;y<n+n;y++)
                     g[x][y]=map[x][y]; 
             int res=max_flow(n,i);
             if(res<ans) ans=res;
         }
         printf("%d\n",ans);
    }
}
