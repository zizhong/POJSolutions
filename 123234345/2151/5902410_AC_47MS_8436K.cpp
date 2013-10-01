#include<stdio.h>
#include<string.h>
double dp[1001][31][31],big[1001][31],small[1001][31],p[1001][31];
int main()
{
    int m,t,N;
    while(scanf("%d%d%d",&m,&t,&N),m||t||N)
    {
         for(int i=1;i<=t;i++)
            for(int j=1;j<=m;j++)
               scanf("%lf",&p[i][j]);
          for(int i=1;i<=t;i++)
         {
             dp[i][0][0]=1;
             for(int j=1;j<=m;j++)
             {
                 dp[i][j][0]=dp[i][j-1][0]*(1-p[i][j]);
                 for(int k=1;k<=j;k++)
                    dp[i][j][k]=dp[i][j-1][k]*(1-p[i][j])+dp[i][j-1][k-1]*p[i][j];
             }
         }
         for(int i=1;i<=t;i++)
         {
              big[i][0]=dp[i][m][0];
              for(int j=1;j<=m;j++)
                  big[i][j]=big[i][j-1]+dp[i][m][j];
              small[i][m]=dp[i][m][m];
              for(int j=m-1;j>=0;j--)
                  small[i][j]=small[i][j+1]+dp[i][m][j];
         }
         double p1=1.0,p2=1.0;
         for(int i=1;i<=t;i++)
             p1*=small[i][1];
         for(int j=1;j<=t;j++)
             p2*=(big[j][N-1]-big[j][0]);
         printf("%.3f\n",p1-p2);
    }
}
