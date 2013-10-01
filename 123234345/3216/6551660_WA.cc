#include<stdio.h>
#include<string.h>
const int Q=21,M=201;
int q,m,map[Q][Q],p[M],t[M],d[M];
int vst[M],g[M][M],nv[M],mv[M];
int dfs(int n_v)
{
    for(int i=0;i<m;i++)
       if(vst[i]==0&&g[n_v][i])
       {
           vst[i]=1;
           if(mv[i]==-1||dfs(i))
           {
               mv[i]=n_v;
               nv[n_v]=i;
               return 1;
           }
           
       }
    return 0;
}
int main()
{
    while(scanf("%d%d",&q,&m),q+m)
    {
        for(int i=0;i<q;i++)
           for(int j=0;j<q;j++)
              scanf("%d",&map[i][j]);
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&p[i],&t[i],&d[i]);
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
           for(int j=0;j<m;j++)
              if(t[i]+d[i]+map[i][j]<=t[j]) g[i][j]=1;
        memset(nv,-1,sizeof(nv));
        memset(mv,-1,sizeof(mv));
        int ans=0;
        for(int i=0;i<m;i++)
           for(int j=0;j<m;j++)
              if(g[i][j]&&mv[j]==-1) {nv[i]=j,mv[j]=i,ans++;break;}
        for(int i=0;i<m;i++)
           if(dfs(i))
           {
                memset(vst,0,sizeof(vst));
                if(dfs(i)) ans++;
           }
           printf("%d\n",m-ans);
    }
}
