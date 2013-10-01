#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
const int MAXN = 55;
int ans[MAXN];
int n, a[MAXN], b[MAXN];
char str1[MAXN], str2[MAXN];
int min(int a,int b){if(a<=b) return a;else return b;}
int max(int a,int b){if(a>=b) return a;else return b;}
void input()
{
       char s[10];
       scanf("%d", &n);
       for(int i = 0; i < n; i ++) {
             scanf("%s %d",s, &a[i]);
             str1[i] = s[0];
       }
}
int DP()
{
       int i, j, k,r;
       int dp[MAXN][MAXN][2];
       for(i = 0; i < n; i ++)
             dp[i][i][0] = dp[i][i][1] = b[i];
       for(r=2;r<=n;r++)//链长
       {
         for(i=0;i<=n-r;i++)//起点下标
         {
           j=i+r-1;//终点下标
           dp[i][j][0]=100000;
           dp[i][j][1]=-100000;
            for(k=i;k<j;k++)
            {
              if(str2[k]=='t')
              {
                dp[i][j][0]=min(dp[i][j][0],dp[i][k][0]+dp[k+1][j][0]);
                dp[i][j][1]=max(dp[i][j][1],dp[i][k][1]+dp[k+1][j][1]);
              }
              else
              {
                 int t=dp[i][j][0];
                 t=min(t,dp[i][k][0]*dp[k+1][j][0]);
                 t=min(t,dp[i][k][0]*dp[k+1][j][1]);
                 t=min(t,dp[i][k][1]*dp[k+1][j][1]);
                 t=min(t,dp[i][k][1]*dp[k+1][j][0]);
                 dp[i][j][0]=t;
                 t=dp[i][j][1];
                 t=max(t,dp[i][k][0]*dp[k+1][j][0]);
                 t=max(t,dp[i][k][0]*dp[k+1][j][1]);
                 t=max(t,dp[i][k][1]*dp[k+1][j][1]);
                 t=max(t,dp[i][k][1]*dp[k+1][j][0]);
                dp[i][j][1]=t;
              }
    
          }

     
      }
    
    }
       return dp[0][n - 1][1];
}

int main()
{
       input();
       int i, j, mx = -100000;
       for(i = 0; i < n; i ++)
       {
             for(j = 0; j < n; j ++)
             {
                  b[j] = a[(i + j) % n];
                  if(j < n-1) str2[j] = str1[(i + j + 1) % n];
             }
             ans[i] = DP();
             if(mx < ans[i])  mx = ans[i];
       }
       printf("%d\n", mx);
       for(i = 0; i < n; i ++)
             if(mx == ans[i]) printf("%d ", i + 1 );
       printf("\n");
       return(0);
}



