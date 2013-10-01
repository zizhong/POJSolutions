#include<stdio.h>
#include<string.h>
const int N=20,M=210;
__int64 f[N][M];
__int64 dp(int n,int k)
{
    if(n==1)
        return !k;
    if(f[n][k]!=-1) return f[n][k];
    __int64 ans=0;
    for(int i=1;i<=n && i-1 <=k ;i++)
    {
           ans+=dp(n-1,k-i+1);
    }
    return f[n][k]=ans;
}
int main()
{
    memset(f,-1,sizeof(f));
    int n,k;
    while(scanf("%d%d",&n,&k),n)
    {
          printf("%I64d\n",dp(n,k));
    }
}
