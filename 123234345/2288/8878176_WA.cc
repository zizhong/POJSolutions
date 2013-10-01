#include<stdio.h>
#include<iostream>
using namespace std;
__int64 f[(1<<13)+10][16][16],way[(1<<13)+10][16][16];
int w[16],n,m;
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int g[16][16]={0};
         scanf("%d%d",&n,&m);
         int N=1<<n;
         for(int i=0;i<N;i++)
         {
              for(int j=0;j<n;j++) for(int k=0;k<n;k++)
                   f[i][j][k]=-1,way[i][j][k]=0; 
         }
         for(int i=0;i<n;i++)
             scanf("%d",&w[i]);
         for(int i=0;i<m;i++)
         {
              int u,v;
              scanf("%d%d",&u,&v);
              --v,--u;
              g[u][v]=g[v][u]=1;
              f[(1<<u)|(1<<v)][u][v]  =f[(1<<u)|(1<<v)][v][u]   =w[u]+w[v]+w[u]*w[v];
              way[(1<<u)|(1<<v)][v][u]=way[(1<<u)|(1<<v)][u][v]=1;
         }
         if(n==1)
         {
               printf("%d 1\n",w[0]);
               continue;
         }
         for(int q=3;q<N;q++)
         {
              for(int i=0;i<n;i++) if(q&(1<<i))
                   for(int j=0;j<n;j++) if(i!=j&&(q&(1<<j))&&f[q][i][j]>0)
                   {
                        for(int k=0;k<n;k++) if(!(q&(1<<k))&&g[k][j])
                        {
                             int ns=q|(1<<k),nf=f[q][i][j]+w[k]+w[j]*w[k]+(g[i][k]?w[i]*w[j]*w[k]:0);
                             if(nf>f[ns][j][k])
                             {
                                   f[ns][j][k]=nf;
                                   way[ns][j][k]=way[q][i][j];
                             }
                             else if(nf==f[ns][i][k])
                             {
                                  way[ns][j][k]+=way[q][i][j];
                             }
                        }
                   }
         }
         __int64 ans=0,ways=0;
         for(int i=0;i<n;i++)
             for(int j=0;j<n;j++) if(i!=j)
             {
                  if(ans<f[N-1][i][j])
                  {
                      ans=f[N-1][i][j];
                      ways=way[N-1][i][j];
                  }
                  else if(ans==f[N-1][i][j])
                  {
                      ways+=way[N-1][i][j];
                  }
             }
         //printf("%I64d %I64d\n",ans,ways/2);
         cout<<ans<<' '<<ways/2<<endl;
    }
}
