#include<cstdio>
#include<cstring>
const int mod=9937;
int f[81][10001];
void solve()
{
    f[1][0]=1;
    f[2][1]=1;
    for(int i=2;i<=80;i++)
        for(int j=i-1;j<=i*(i-1)/2 && j<=10000 ;j++)
             f[i][j]=(f[i-1][j-2]*(i-2) +2*f[i-1][j-1])%mod;
}
int main()
{
    solve();
    int n,m;
    while(scanf("%d%d",&n,&m),n)
         printf("%d\n",f[n][m]);
}
