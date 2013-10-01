#include<stdio.h>
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a!=-1)
    {
         int g[25][25]={0};
         g[a][b]=1;
         while(scanf("%d%d",&a,&b),a+b)
             g[a][b]=1;
         int n=0;
         while(1)
         {
                 int flag=1;
                 for(int i=1;i<=24;i++)
                    for(int j=1;j<=24;j++)
                        if(g[i][j]) {flag=0;break;}
                 if(flag) break;
                 n++;
                 int num[25][25]={0};
                 for(int i=24;i>=1;i--)
                    for(int j=1;j<=24;j++)
                    {
                        if(i==24||j==1) num[i][j]=0;
                        else num[i][j]=num[i][j-1]+num[i+1][j]-num[i+1][j-1]+g[i+1][j-1];
                    }
                 for(int i=1;i<=24;i++)
                    for(int j=1;j<=24;j++)
                        if(num[i][j]==0) g[i][j]=0;
         }
         printf("%d\n",n);
    }
}
