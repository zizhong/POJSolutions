#include<stdio.h>
#include<string.h>
const int N=503;
int n,m,g[N][N],nv[N],mv[N],vst[N];
int dfs(int n_v)
{
    for(int i=0;i<n;i++)
       if(vst[i]==0&&g[n_v][i])
       {
           vst[i]=1;
           if(mv[i]==-1||dfs(mv[i]))
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
    while(scanf("%d%d",&n,&m),n+m)
    {
          memset(g,0,sizeof(g));
          int a,b;
          for(int i=0;i<m;i++)
          {
               scanf("%d%d",&a,&b);
               g[a-1][b-1]=1;
          }
          for(int k=0;k<n;k++)
             for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(g[i][k]&g[k][j]) g[i][j]=1;
          int ans=0;
          memset(nv,-1,sizeof(nv));
          memset(mv,-1,sizeof(mv));
          for(int i=0;i<n;i++)
             if(nv[i]==-1)
             for(int j=0;j<n;j++)
                if(g[i][j]&&mv[j]==-1)
                {
                     nv[i]=j,mv[j]=i,ans++;
                     break;
                }
          for(int i=0;i<n;i++)
             if(nv[i]==-1)
             {
                  memset(vst,0,sizeof(vst));
                  if(dfs(i)) ans++;
             }
          printf("%d\n",n-ans);
    }
}
