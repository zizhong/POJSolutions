#include<stdio.h>
const int N=51;
char map[N][N];
__int64 f[N][N]={1};
__int64 gcd(__int64 a,__int64 b){return b?gcd(b,a%b):a;}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
          for(int j=1;j<=i;j++)
                  while((map[i][j]=getchar())!='.'&&map[i][j]!='*') ; 
    __int64 k2=(__int64)(1)<<n;
    for(int i=0;i<n;i++)
    {
          for(int j=0;j<=i;j++)
          {
                  if(map[i+1][j+1]=='*') f[i+1][j]+=f[i][j],f[i+1][j+1]+=f[i][j];
                  else f[i+2][j+1]+=f[i][j]*4;
          }
    }
    /*for(int i=0;i<=n+1;i++)
    {
            for(int j=0;j<=n+1;j++)
               printf(" %I64d",f[i][j]);
            puts("");
    }*/
    __int64 k1=f[n][m];
    __int64 d=gcd(k1,k2);
    printf("%I64d/%I64d\n",k1/d,k2/d);
}
