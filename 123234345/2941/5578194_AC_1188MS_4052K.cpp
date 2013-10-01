#include<stdio.h>
#define N 1001
int f[N][N];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)&&n)
    {
        int flag=1;
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
             scanf("%d",&f[i][j]);
        for(i=1;i<n-1&&flag;i++)
           for(j=1;j<n-1&&flag;j++)
               if((f[i][j]+f[i+1][j+1])!=(f[i][j+1]+f[i+1][j])) flag=0;
        if(flag) printf("homogeneous\n");
        else printf("not homogeneous\n");
    }
}
