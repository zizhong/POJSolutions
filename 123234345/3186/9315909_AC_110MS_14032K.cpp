#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=2011,inf=0x3fffffff;
int dp[N][N],d[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for(int i=0;i<=n;i++)
       for(int j=0;j+i<=n;j++)
            dp[i][j]=-inf;
    dp[0][0]=0;
    for(int k=0;k<=n;k++)
       for(int i=0;i<=k;i++)
        {
            int j=k-i;
            if(dp[i][j]==-inf || k==n) continue;
            dp[i+1][j]=max(dp[i][j]+d[i+1]*(k+1),dp[i+1][j]);
            dp[i][j+1]=max(dp[i][j]+d[n-j]*(k+1),dp[i][j+1]);
        }
    int ans=0;
    for(int i=0;i<=n;i++)
         ans=max(ans,dp[i][n-i]);
    printf("%d\n",ans);
}
