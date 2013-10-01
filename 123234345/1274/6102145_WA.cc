#include<stdio.h>
const int N=200;
int n,m,nv[N],mv[N],vst[N],g[N][N];
int dfs(int n_v,int level)
{
    for(int i=1;i<=m;i++)
       if(vst[i]!=level&&g[n_v][i])
       {
            vst[i]=level;
            if(mv[i]==-1||dfs(mv[i],level))
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
    while(scanf("%d%d",&n,&m)!=EOF)
    {
    for(int i=1;i<=n;i++)
    {
        int d;
        scanf("%d",&d);
        while(d--)
        {
             int x;
             scanf("%d",&x);
             g[i][x]=1;
        }
    }
    for(int i=0;i<N;i++)
        nv[i]=mv[i]=-1;
    int ans=0;
    for(int i=0;i<n;i++)
         if(nv[i]==-1)
              if(dfs(i,i+1)==1) ans++;
    printf("%d\n",ans);
    }
}
