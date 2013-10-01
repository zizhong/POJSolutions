#include<stdio.h>
const int N=129;
int main()
{
    int n;
    while(scanf("%d",&n),n+1)
    {
         double p[N][N]={0},w[8][N]={0};
         int m=1<<n;
         for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                scanf("%lf",&p[i][j]);
         for(int i=0;i<n;i++)
         {
               for(int j=0;j<m;j++)
               {
                       int loc=((j>>i)^1)<<i;
                       for(int k=loc;k<loc+(1<<i);k++)
                           w[i][j]+=w[i-1][j]*p[j][k];
               }
         }
         int win=0;
         for(int i=1;i<m;i++)
             if(w[n-1][win]<w[n-1][i]) win=i;
         printf("%d\n",win+1);
    }
}
