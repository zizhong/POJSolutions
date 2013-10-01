#include<cstdio>
#include<cstring>
const int N=52,M=N*N/2,d[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,0},{0,1},{1,0},{0,-1}};
int n,m,g[N][N],idx[N][N];
bool map[M][M],nv1,nv2;
void dismap()
{     
     for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=m;j++)
            printf("%d ",g[i][j]); 
     printf("%d %d\n",nv1,nv2);
     for(int i=0;i<nv1;i++,puts(""))
         for(int j=0;j<nv2;j++) printf("%d ",map[i][j]);
     
}
void buildG()
{
     nv1=nv2=0;
     for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
           if(g[i][j]!=-1) 
               idx[i][j]=((i+j)&1)?nv1++:nv2++;
     memset(map,0,sizeof(map));
     for(int i=1;i<=n;i++)
         for(int j=1;j<=m;j++) if(g[i][j]>0)
         {
             int u=idx[i][j];
             for(int k=0;k<12;k++) if((g[i][j]>>k)&1)
             {
                 int ni=i+d[k][0],nj=j+d[k][1];
                 if(ni>0&&ni<=n&&nj>0&&nj<=m&&g[ni][nj]>0)
                 {
                       int v=idx[ni][nj];
                       if((i+j)&1) map[u][v]=1;
                       else map[v][u]=1;
                 }
             }
         }
}
int nv[M],nu[M],vst[M];
bool dfs(int v)
{
     for(int u=0;u<nv2;u++) if(g[v][u] && vst[u]==0)
     {
          vst[u]=1;
          if(nu[u]==-1||dfs(nu[u]))
          {
               nv[v]=u,nu[u]=v;
               return true;
          }
     }
     return false;
}
int  max_match()
{
     memset(nv,-1,sizeof(nv));
     memset(nu,-1,sizeof(nu));
     int ans=0;
     for(int i=0;i<nv1;i++) if(nv[i]==-1)
        for(int j=0;j<nv2;j++) if(map[i][j]&&nu[j]==-1)
        {
              nv[i]=j,nu[j]=i,ans++;
              break;
        } 
     for(int i=0;i<nv1;i++) if(nv[i]==-1)
     {
          memset(vst,0,sizeof(vst));
          if(dfs(i)) ans++;
     }
     return ans;
}
int main()
{    int T=0;
    while(scanf("%d%d",&n,&m),n)
    {
         for(int i=1;i<=n;i++)
             for(int j=1;j<=m;j++)
                 scanf("%d",&g[i][j]);
         buildG();
         int maxmatch=max_match();
         printf("%d. %d\n",++T,maxmatch);
    }
}
