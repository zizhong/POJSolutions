#include<stdio.h>
#include<string.h>
const int inf=(int)(1e9+10);
const int M=110,N=510;
int f[M][N],way[M][N],v[M][N];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
         memset(f,0,sizeof(f));
         memset(v,0,sizeof(v));
         for(int i=1;i<=n;i++)
             for(int j=1;j<=m;j++)
             {
                 scanf("%d",&v[i][j]);
                 if(i==1) f[i][j]=v[i][j];
                 else f[i][j]=inf;
                 way[i][j]=0;
             }
         for(int i=1;i<=n;i++)
         {
              for(int j=1;j<=m;j++)
              {
                   for(int k=j-1;k>=1;k--)
                   {
                       if(f[i][k]>f[i][k+1]+v[i][k])
                       {
                            f[i][k]=f[i][k+1]+v[i][k];
                            way[i][k]=1;
                       } else break;
                   }
                   for(int k=j+1;k<=m;k++)
                   {
                       if(f[i][k]>f[i][k-1]+v[i][k])
                       {
                            f[i][k]=f[i][k-1]+v[i][k];
                            way[i][k]=2;
                       }else  break;
                   }
              }
              for(int j=1;j<=m;j++)
                   f[i+1][j]=f[i][j]+v[i+1][j];
         }
         int ans=inf,mi=0;
         for(int i=1;i<=m;i++)
             if(ans>f[n][i]) ans=f[n][i],mi=i;
         int st[N*M],top=0;
         st[top++]=mi;
         int y=n,x=mi;
         while(y>1)
         {
              switch(way[y][x])
              {
                  case 0:y--;break;
                  case 1:x++;break;
                  case 2:x--;break;
              }
              st[top++]=x;
         }
         while(top)
         {
              printf("%d\n",st[--top]);
         }
    }
}
