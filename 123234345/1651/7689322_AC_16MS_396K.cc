#include<stdio.h>
const int N=101;
int d[N],f[N][N];
const int inf=0xfffffff;
int min(int a,int b){return a>b?b:a;}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         for(int i=0;i<n;i++)
             scanf("%d",&d[i]);
         for(int i=0;i<n;i++) 
             for(int j=i+2;j<n;j++)
                f[i][j]=inf;
         for(int len=3;len<=n;len++)
            for(int i=0;i+len-1<n;i++)
            {
                 int j=i+len-1;
                 for(int k=i+1;k<j;k++)
                 {
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]+d[i]*d[k]*d[j]);
                 }
            }
         printf("%d\n",f[0][n-1]);
    }
}
