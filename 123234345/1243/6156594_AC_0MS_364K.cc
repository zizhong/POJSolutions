#include<stdio.h>
int main()
{
    int n,m,T=0;
    while(scanf("%d%d",&m,&n),n+m)
    {
         T++;
         int f[31][31]={0};
         for(int i=0;i<=m;i++) f[i][0]=i;
         for(int i=0;i<=n;i++) f[1][i]=1;
         for(int i=2;i<=m;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=f[i-1][j-1]+f[i-1][j]+1;
         printf("Case %d: %d\n",T,f[m][n]);
    }
}