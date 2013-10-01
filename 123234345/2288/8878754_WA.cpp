#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
__int64 f[10000][16][16],way[10000][16][16];
int w[16],n,m;
int main()
{    int T;
    for(scanf("%d",&T);T--;)
    {
         int g[16][16];
         scanf("%d%d",&n,&m);
         int N=1<<n;
         memset(g,0,sizeof(g));
         memset(f,-1,sizeof(f));
         memset(way,0,sizeof(way));
         for(int i=0;i<n;i++)
             scanf("%d",&w[i]);
         for(int i=0;i<m;i++)
         {
              int u,v;
              scanf("%d%d",&u,&v);
              --v,--u;
              g[u][v]=g[v][u]=1;
         }
         for(int i=0;i<n;i++)
              for(int j=0;j<n;j++) if(i!=j)
              {
                   f[(1<<i)|(1<<j)][i][j]=w[i]+w[j]+w[i]*w[j];
                   way[(1<<i)|(1<<j)][i][j]=1;
              }
         if(n==1)
         {
               printf("%d 1\n",w[0]);
               continue;
         }
         for(int q=3;q<N;q++)
         {
              for(int i=0;i<n;i++) if(q&(1<<i))
                   for(int j=0;j<n;j++) if(i!=j&&(q&(1<<j))&&f[q][i][j]!=-1)
                   {
                        for(int k=0;k<n;k++) if(!(q&(1<<k))&&g[k][j])
                        {
                             int ns=q|(1<<k),nf=f[q][i][j]+w[k]+w[j]*w[k]+0;
                             if(g[i][k]) nf+=w[i]*w[j]*w[k];
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
         if(ans>0) cout<<ans<<' '<<ways/2<<endl;
         else cout<<"0 0"<<endl;
    }
}
