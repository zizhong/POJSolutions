#include<stdio.h>
const int N=1000001,C=102;
double f[2][C/2];
int main()
{
    int c,n,m,i,j;
    while(scanf("%d%d%d",&c,&n,&m)==3&&c)
    {
          if(c<m||n<m||((n&1)-(m&1)))
          {
                puts("0.000");
                continue;
          }
          if(n>1001) n=1000+(n&1);
          for(i=0;i<C/2;i++) f[0][i]=0; 
          f[0][0]=1;
          for(i=1;i<=n;i++)
          {
                 for(j=0;j<C/2;j++) f[i&1][j]=0;
                 for(j=0;j<=(c+1)/2;j++) 
                 {
                        if(i&1)
                               if((j+1)*2>c) f[1][j]=f[0][j]*(c-2*j)/c;
                               else f[1][j]=(f[0][j]*(c-2*j)+f[0][j+1]*(j+1)*2)/c;
                        else
                               if(j) f[0][j]=(f[1][j-1]*(c-2*j+1)+f[1][j]*(2*j+1))/c;
                               else f[0][j]=f[1][j]/c;
                 }
          }
          printf("%.3lf\n",f[n&1][m>>1]);
    }
}
