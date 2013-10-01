#include "stdio.h"
#include "string.h"
#include "algorithm"
using namespace std;
int DP[368][368];
struct DAY
{
    int x,y,m;
}D[1010];
bool cmp(const DAY &A,const DAY &B)
{
    if(A.y == B.y) return A.x < B.x;
    return A.y < B.y;
}
void BIG(int &x,int y)
{
    if(x < y) x = y;
}
int main()
{
    int i,N,j,k,max;
    while(scanf("%d",&N) && N)
    {
           for(i = 1;i <= N;i ++)
                 scanf("%d%d%d",&D[i].x,&D[i].y,&D[i].m);
           memset(DP,0,sizeof(DP));
           sort(D+1,D+N+1,cmp);
           for(i = 1;i <= N;i ++)
           {
                for(j = 0;j <=365;j ++)
                {
                     BIG(DP[D[i].y][j],DP[D[i].x-1][j]+D[i].m);
                     BIG(DP[j][D[i].y],DP[j][D[i].x-1]+D[i].m);
                }
                if(i == N) break;
                for(j = D[i].y+1;j <= D[i+1].y;j ++)
                {
                     for(k = 0;k <= D[i+1].y;k ++)
                     {
                          BIG(DP[j][k],DP[j-1][k]);
                          BIG(DP[k][j],DP[k][j-1]);
                     }
                }
           }
           max = 0;
           for(j = 0;j <= 365;j ++)
                 for(k = 0;k <= 365;k ++)
                    if(max < DP[j][k])
                         max = DP[j][k];
           printf("%d\n",max);
    }
    return 0;
}


