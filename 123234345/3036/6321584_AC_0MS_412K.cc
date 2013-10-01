#include<stdio.h>
int dp[15][29][29];
int d[][2]={{-1,-1},{0,-1},{1,0},{1,1},{0,1},{-1,0}};
bool scope(int a){return a>=0&&a<29;}
int main()
{
    dp[0][14][14]=1;
    for(int i=1;i<=14;i++)
       for(int x=0;x<29;x++)
          for(int y=0;y<29;y++)
             for(int  l=0;l<6;l++)
                 if(scope(x+d[l][0])&&scope(y+d[l][1]))
                    dp[i][x][y]+=dp[i-1][x+d[l][0]][y+d[l][1]];
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         printf("%d\n",dp[n][14][14]);
    }
}
