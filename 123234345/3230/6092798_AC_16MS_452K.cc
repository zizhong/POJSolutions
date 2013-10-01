#include<stdio.h>
const int N=101,inf=-99999999;
int _max(int a,int b){return a>b?a:b;}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
         int in[N][N]={0},out[N][N]={0},f[N][N]={0};
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 scanf("%d",&out[i][j]);
         for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
               scanf("%d",&in[i][j]),f[i][j]=inf;
         for(int i=1;i<=n;i++)
             f[1][i]=in[1][i]-out[1][i];
         for(int i=2;i<=m;i++)
         {
             for(int j=1;j<=n;j++)
             {
                    int max=inf;
                    for(int k=1;k<=n;k++)
                       max=_max(max,f[i-1][k]+in[i][j]-out[k][j]);
                    f[i][j]=max;
             }
         }
         int ans=inf;
         for(int i=1;i<=n;i++)
             ans=_max(ans,f[m][i]);
         printf("%d\n",ans);
    }
}
