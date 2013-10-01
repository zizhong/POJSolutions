#include<stdio.h>
const int N=101;
int main()
{
    int n,m;
    while(scanf("%d",&n),n)
    {
         scanf("%d",&m);
         int d[N];
         char s[8];
         for(int i=0;i<n;i++)
         {
              scanf("%s",s);
              d[i]=0;
              for(int j=0;j<4;j++)
                  d[i]=d[i]*10+s[j]-'0';
         }
         int g[N][N]={0},sum[N]={0},min[N]={0};
         for(int i=1;i<=m;i++)
         {
              scanf("%d%d",&sum[i],&min[i]);
              for(int k=1;k<=sum[i];k++)
              {
                   scanf("%s",s);
                   int v=0;
                   for(int j=0;j<4;j++)
                        v=v*10+s[j]-'0';
                   g[i][k]=v;
              }
         }
         int flag=1;
         int r[N]={0};
         for(int i=0;i<n;i++)
             for(int j=1;j<=m;j++)
                 for(int k=1;k<=sum[j];k++)
                      if(g[j][k]==d[i]) r[j]++;
         for(int i=1;flag&&i<=m;i++)
             if(r[i]<min[i]) flag=0;
             //printf("%d ",r[i]);
         puts(flag?"yes":"no");
    }
}
