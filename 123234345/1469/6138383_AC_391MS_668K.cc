#include<stdio.h>
#include<string.h>
const int N=100,M=300;
int g[N][M],vst[M],lanx[N],lany[M];
int n,m,ii;
int dfs(int x,int level)
{
    for(int y=0;y<m;y++)
       if(g[x][y]&&vst[y]!=level)
       {
           vst[y]=level;
           if(lany[y]==-1||dfs(lany[y],level))
           {
               lany[y]=x;
               lanx[x]=y;
               return 1;
           }
       }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         memset(g,0,sizeof(g));
         scanf("%d%d",&n,&m);
         for(int i=0;i<n;i++)
         {
              int ni,j;
              scanf("%d",&ni);
              while(ni--)
              {
                   scanf("%d",&j);
                   g[i][j-1]=1;
              }
         }
         if(n>m) {puts("NO");continue;}
         int ans=0;
         memset(lanx,-1,sizeof(lanx));
         memset(lany,-1,sizeof(lany));
         for(int i=0;i<n;i++)
             for(int j=0;j<m&&lanx[i]==-1;j++)
                 if(g[i][j]&&lany[j]==-1)
                     lany[j]=i,lanx[i]=j,ans++;
         for(int i=0;i<n;i++)
            if(lanx[i]==-1)
            {
                 ii++;
                 if(dfs(i,ii)) ans++;
            }
         puts(ans==n?"YES":"NO");
    }
}
