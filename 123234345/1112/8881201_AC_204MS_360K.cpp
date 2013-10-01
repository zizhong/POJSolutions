#include<stdio.h>
#include<cstring>
const int N=110;
int d[N][N],g[N][N],n,flag;
int scc[N][2],sccn,col[N],num[N];
void dying(int v,int c)
{
     scc[sccn][c]++;
     col[v]=c;
     num[v]=sccn;
     for(int i=1;i<=n;i++) if(i!=v&&g[v][i])
     {
          if(col[i]==c){flag=0;return ;}
          if(col[i]==(c^1)) continue;
          dying(i,c^1);
     }
}

int f[N][N],p[N][N];
int main()
{
    while(scanf("%d",&n)==1)
    {
         memset(d,0,sizeof(d));
         for(int i=1;i<=n;i++)
         {
              int j;
              while(scanf("%d",&j),j) d[i][j]=1;
         }
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                 g[i][j]=!(d[i][j]&&d[j][i]);
         
         memset(col,-1,sizeof(col));
         sccn=0;
         flag=1;
         for(int i=1;flag&&i<=n;i++)
              if(col[i]==-1)
              {
                  dying(i,1);
                  sccn++;
              }
         if(!flag) {puts("No solution");continue;}
         /*for(int i=1;i<=n;i++)
         {
              printf("%d %d\n",num[i],col[i]);
         }puts("~~~~");*/
         memset(f,0,sizeof(f));
         memset(p,-1,sizeof(p));
         f[0][0]=1;
         for(int i=0;i<sccn;i++)
            for(int j=0;j<=n/2;j++) if(f[i][j])
            {
                 if(j+scc[i][0]<=n/2) f[i+1][j+scc[i][0]]=1,p[i+1][j+scc[i][0]]=0;
                 if(j+scc[i][1]<=n/2) f[i+1][j+scc[i][1]]=1,p[i+1][j+scc[i][1]]=1;
            }
         /*for(int i=0;i<=sccn;i++,puts(""))
         {
              for(int j=0;j<=n/2;j++) printf("%d ",f[i][j]);
         }puts("~~`");
         for(int i=0;i<=sccn;i++,puts(""))
         {
              for(int j=0;j<=n/2;j++) printf("%d ",p[i][j]);
         }puts("~~`");*/
         int ans=n/2;
         while(f[sccn][ans]==0) ans--;
         printf("%d",ans);
         int x=sccn,y=ans;
         int choose[N];
         while(x>=1)
         {
              choose[x]=p[x][y];
              y-=scc[x-1][p[x][y]];
              x--;
         }
         //for(int i=1;i<=sccn;i++) printf("%d ",choose[i]);puts("");
         for(int i=1;i<=n;i++)
              if(col[i]==choose[num[i]+1]) printf(" %d",i);puts("");
         printf("%d",n-ans);
         for(int i=1;i<=n;i++)
              if(col[i]!=choose[num[i]+1]) printf(" %d",i);puts("");
    }
}
