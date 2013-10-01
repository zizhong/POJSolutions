#include<cstdio>
#include<cstring>
const int C=110,N=2000*C,MID=N>>1,inf=1<<30;
int dp[2][N],f[C],s[C];
int main()
{    int n;
    while(scanf("%d",&n)==1)
    {
    for(int i=0;i<n;i++)
          scanf("%d%d",&f[i],&s[i]);
    int l=MID,r=MID;
    for(int i=0;i<N;i++) dp[0][i]=dp[1][i]=-inf;
    dp[0][MID]=0;
    int now=1;
    for(int i=0;i<n;i++) if(!(f[i]<0&&s[i]<0))
    {
         int ll=l,rr=r;
         for(int j=0;j<N;j++) dp[now][i]=-inf;
         for(int j=l;j<=r;j++) if(dp[now^1][j]!=-inf)
         {
              if(dp[now][j+f[i]]<dp[now^1][j]+f[i]+s[i])
              {
                  dp[now][j+f[i]]=dp[now^1][j]+f[i]+s[i];
                  if(j+f[i]>rr) rr=j+f[i];
                  if(j+f[i]<ll) ll=j+f[i];
              }
         }
         l=ll,r=rr;
         for(int j=l;j<=r;j++) if(dp[now][j]<dp[now^1][j]) dp[now][j]=dp[now^1][j];
         now^=1;
    }
    int ans=0;
    for(int i=MID;i<N;i++) if(dp[now^1][i]-(i-MID)>=0 && dp[now^1][i]>ans)
         ans=dp[now^1][i];
    printf("%d\n",ans);
    }
}

