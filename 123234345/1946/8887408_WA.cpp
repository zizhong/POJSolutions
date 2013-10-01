#include<stdio.h>
const int N=110,inf=1000;
int f[21][N][N];
int n,e,d;
int main()
{    scanf("%d%d%d",&n,&e,&d);
    if(e<d) {puts("0");return 0;}
    for(int i=0;i<=n;i++)
        for(int j=0;j<=e;j++)
            for(int k=0;k<=d;k++)
                f[i][j][k]=inf;
    f[1][e][0]=0;
    for(int i=1;i<=n;i++)
       for(int j=e;j>0;j--)
           for(int k=0;k<d;k++)
           {
                if(e-k>j && i+1 <= n && f[i+1][e-k][k] >f[i][j][k]) 
                     f[i+1][e-k][k] =  f[i][j][k];
                for(int s=1;s*s<=j;s++)
                {
                     int k2=k+s;
                     if(k2>d) k2=d;
                     if(f[i][j-s*s][k2]>f[i][j][k]+1)
                          f[i][j-s*s][k2]=f[i][j][k]+1;
                }
           }
    int ans=inf;
    for(int i=0;i<=n;i++) for(int j=0;j<=e;j++)
         if(ans > f[i][j][d]) ans=f[i][j][d];
    printf("%d\n",ans);
             
}
