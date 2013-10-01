#include<stdio.h>
#include<string.h>
const int N=100,M=100;
int g[N][M],nv[N],mv[N],vst[M],n,m;;
int dfs(int n_v)
{
    for(int i=0;i<m;i++)
    {
         if(!vst[i]&&g[n_v][i])
         {
              vst[i]=1;
              if(mv[i]==-1||dfs(mv[i]))
              {
                  mv[i]=n_v;
                  nv[n_v]=i;
                  return 1;
              }
         }
    }
    return 0;
}
int main()
{    
    double s,v;
    while(scanf("%d%d%lf%lf",&n,&m,&s,&v)!=EOF)
    {
         double s1[N][2],t1[N][2];
         for(int i=0;i<n;i++) scanf("%lf%lf",&s1[i][0],&s1[i][1]);
         for(int i=0;i<m;i++) scanf("%lf%lf",&t1[i][0],&t1[i][1]);
         double d2[N][M];
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
               d2[i][j]=(s1[i][0]-t1[j][0])*(s1[i][0]-t1[j][0])+(s1[i][1]-t1[j][1])*(s1[i][1]-t1[j][1]);
         memset(g,0,sizeof(g));
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(d2[i][j]<=v*v*s*s) g[i][j]=1;
         int max=0;
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         for(int i=0;i<n;i++)
         {
              if(nv[i]==-1)
              {
                  memset(vst,0,sizeof(vst));
                  if(dfs(i)) max++;
              }
         }
         printf("%d\n",n-max);
    }
}
