#include<stdio.h>
int main()
{
    int f[101][101]={0};
    int n,m,i,j,k,r=-99999999;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
       for(j=1;j<=m;j++)
         scanf("%d",&f[i][j]);
    for(i=2;i<=n;i++)
      for(j=2;j<=m;j++)
      {
         int max=-9999999;
         for(k=i-1;k<j;k++)
           if(max<f[i-1][k]) max=f[i-1][k];
         if(max!=-9999999)
          f[i][j]+=max;
      }
    /*for(i=1;i<=n;i++)
    {
       for(j=1;j<=m;j++)
       printf("%d ",f[i][j]);
       printf("\n");
    }*/
    for(i=n;i<=m;i++)
      if(r<f[n][i]) r=f[n][i];
    printf("%d\n",r);
}
