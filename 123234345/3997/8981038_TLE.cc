#include<cstdio>
#include<cstring>
int n,m;
int g[256][256];
int v[256];
int x,y;
void dfs(int cur)
{
     v[cur]=1;
     if(v[x]) return ;
     for(int i=1;i<=n;i++) if(g[cur][i] && !v[i])
         dfs(i);
}
bool ok()
{
     for(int i=1;i<=n;i++) v[i]=0;
     dfs(y);
     return v[x];
}
int main()
{
    int T=0;
    while(scanf("%d%d",&n,&m),n)
    {
         for(int i=1;i<=n;i++) 
             for(int j=1;j<=n;j++)
                 g[i][j]=0;
         int ans=0;
         while(m--)
         {
             scanf("%d%d",&x,&y);
             if(ok()) ans++;
             else
             {
                 g[x][y]=1;
             }
         }
         printf("%d. %d\n",++T,ans);
    }
}
