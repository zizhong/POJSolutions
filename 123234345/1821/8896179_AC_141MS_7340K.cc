#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=16010,K=110;
int dp[K][N];
int q[N],pos[N],head,tail;
struct Node
{
     int p,l,s;
     bool operator < (Node a) const 
     {return s<a.s;}
     void init(){scanf("%d%d%d",&l,&p,&s);}
}w[K];
int n,k;
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
         for(int i=1;i<=k;i++) w[i].init();
         sort(w+1,w+k+1);
         memset(dp,0,sizeof(dp));
         for(int i=1;i<=k;i++)
         {
              int j;
              for(j=0;j<w[i].s;j++) dp[i][j]=dp[i-1][j];
              head=tail=0;
              for(j=max(w[i].s-w[i].l,0);j<w[i].s;j++)
              {
                   int nv=dp[i-1][j]-w[i].p*j;
                   while(head<tail && q[tail-1]<=nv) tail--;
                   q[tail]=nv;
                   pos[tail++]=j;
              }
              for(j=w[i].s;j<=w[i].s+w[i].l-1 && j<=n; j++)
              {
                   while(head<tail && j-pos[head] > w[i].l) head++;
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                   if(head<tail)
                          dp[i][j]=max(dp[i][j],q[head]+j*w[i].p);
              }
              for(;j<=n;j++) dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
         }
         printf("%d\n",dp[k][n]);
    }
}
