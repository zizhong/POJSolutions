#include<stdio.h>
const int N=101;
int g[N][N];
int main()
{
    
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    while(scanf("%d%d",&i,&j)==2) g[i][j]=1;
    int v[N]={0};
    int ans=0;
    for(int i=1;i<=n;i++)
    {
         if(v[i]==0)
         {
              ans++;
              for(int j=i+1;j<=n;j++)
              {
                   int flag=1;
                   for(int k=1;flag&&k<=m;k++)
                      if(g[i][k]!=g[j][k]) flag=0;
                   if(flag) v[j]=1;
              }
         }
    }
    printf("%d\n",ans);
}
