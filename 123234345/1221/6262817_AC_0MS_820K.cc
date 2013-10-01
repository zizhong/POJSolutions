#include<stdio.h>
const int N=250;
int main()
{
    __int64 f[N][N];
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
           if(i*j==0||i==j) f[i][j]=1;
           else f[i][j]=0;
    for(int i=2;i<N;i++)
       for(int j=i-1;j>=1;j--)
         if(i>=2*j) f[i][j]=f[i][j+1]+f[i-2*j][j];
         else f[i][j]=f[i][j+1];
    int n;
    while(scanf("%d",&n),n) printf("%d %I64d\n",n,f[n][1]);
}
