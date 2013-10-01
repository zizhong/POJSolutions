#include<stdio.h>
bool g[101][101];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j,k;
    for(i=1;i<=n;i++)
       g[i][i]=true;
    for(i=0;i<m;i++)
    {
       int b,e;
       scanf("%d%d",&b,&e);
       g[b][e]=true;
    }
    for(k=1;k<=n;k++)
       for(i=1;i<=n;i++)
          for(j=1;j<=n;j++)
            g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
    int num=0;
    for(i=1;i<=n;i++)
    {
        int count=0;
        for(j=1;j<=n;j++)
          count+=g[i][j]+g[j][i];
        if(count==n+1) num++;
    }
    printf("%d\n",num);
    return 0;
}
