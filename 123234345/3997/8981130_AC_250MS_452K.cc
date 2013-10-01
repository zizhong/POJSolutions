#include<cstdio>
#include<cstring>
int n,m;
bool g[256][256];
int main()
{
    int T=0;
    while(scanf("%d%d",&n,&m),n)
    {
         for(int i=1;i<=n;i++) 
             for(int j=1;j<=n;j++)
                 if(i-j) g[i][j]=0;
                 else g[i][j]=1;
         int ans=0;
         while(m--)
         {
             int x,y;
             scanf("%d%d",&x,&y);
             if(g[y][x]) ans++;
             else if(!g[x][y])
             {
                 g[x][y]=1;
                 for(int i=1;i<=n;i++) if(g[i][x])
                      for(int j=1;j<=n;j++) if(g[y][j])
                          g[i][j]=1;
             }
         }
         printf("%d. %d\n",++T,ans);
    }
}
