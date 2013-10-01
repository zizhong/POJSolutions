#include<stdio.h>
const int N=31,inf=1<<30;
int g[N][N],f[N][N][N];
int min(int a,int b){return a>b?b:a;}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          int n;
          scanf("%d",&n);
          for(int i=1;i<n;i++)
              for(int j=i+1;j<=n;j++)
                   scanf("%d",&g[i][j]),g[j][i]=g[i][j];
          for(int i=1;i<=n;i++)
               for(int t1=1;t1<=n;t1++)
                    for(int t2=t1;t2<=n;t2++)
                             f[i][t1][t2]=inf;
          f[1][1][1]=0;
          for(int i=1;i<n;i++)
               for(int t1=1;t1<=i;t1++)
                   for(int t2=t1;t2<=i;t2++)
                       if(f[i][t1][t2]<inf)
                       {
                             int a=t1,b=t2;
                             f[i+1][t1][t2]=min(f[i+1][t1][t2],f[i][t1][t2]+g[i][i+1]);
                             f[i+1][t2][i]=min(f[i+1][t2][i],f[i][t1][t2]+g[t1][i+1]);
                             f[i+1][t1][i]=min(f[i+1][t1][i],f[i][t1][t2]+g[t2][i+1]);
                       }
          int ans=1<<30;
          for(int t1=1;t1<n;t1++)
              for(int t2=t1;t2<n;t2++)
                  if(f[n][t1][t2]<ans) ans=f[n][t1][t2];
          printf("%d\n",ans);
    }
}
