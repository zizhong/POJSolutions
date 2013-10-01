#include<stdio.h>
#include<cstring>
const int N=110;
int xy[N][N],yz[N][N],f[N][N];
int x[N],y[N],z[N],n,m,k;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
int cost(int a,int b){return a>b?a-b:b-a;}
int find_k(int i, int j, int ftp)
{
    int tp, t;
    tp = yz[1][j] + xy[i][1];
    ftp = min(ftp, tp);
    for(t = 2; t <= m; t++)
    {
       tp = yz[t][j] + min(xy[i][t], xy[i][t-1]);
       ftp = min(ftp, tp);
    } 
    return ftp;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         scanf("%d%d%d",&n,&m,&k);
         for(int i=1;i<=n;i++) scanf("%d",&x[i]);
         for(int i=1;i<=m;i++) scanf("%d",&y[i]);
         for(int i=1;i<=k;i++) scanf("%d",&z[i]);
         memset(xy, 0, sizeof(xy));
         memset(yz, 0, sizeof(yz));
         memset(f, 0, sizeof(f));
         //xy[n][i]
         for(int i=1;i<=m;i++)
             xy[n][i]=xy[n][i-1]+cost(x[n],y[i]);
         //xy[i][1]
         for(int i=n;i>=1;i--)
             xy[i][1]=xy[i+1][1]+cost(x[i],y[1]);
         //x[i][j]
         for(int i=n-1;i>=1;i--)
             for(int j=2;j<=m;j++)
                 xy[i][j]=min(min(xy[i][j-1],xy[i+1][j]),xy[i+1][j-1])+cost(x[i],y[j]);
         
         //yz[m][i]
         for(int i=1;i<=k;i++)
              yz[m][i]=yz[m][i-1]+cost(y[m],z[i]);
         //yz[i][1]
         for(int i=m;i>=1;i--)
              yz[i][1]=yz[i+1][1]+cost(y[i],z[1]);
         //yz[i][j]
         for(int i=m-1;i>=1;i--)
              for(int j=2;j<=k;j++)
                  yz[i][j]=min(min(yz[i][j-1],yz[i+1][j]),yz[i+1][j-1])+cost(y[i],z[j]);
         
       //f[n][1]
       int i = n, j = 1;
       int ftp = min(xy[n][m], yz[1][j]) + cost(x[n], z[j]);
       f[i][j] = find_k(i, j, ftp);
       //f[n][j]
       for(i = n, j = 2; j <= k; j++)
       {
            ftp = min(yz[1][j], min(f[i][j-1], yz[1][j-1])) + cost(x[i], z[j]);
            f[i][j] = find_k(i, j, ftp);
       }
       //f[i][j], i < n
       for(i = n-1; i >= 1; i--)
       {
             //f[i][1]
            j = 1;
            ftp = min(f[i+1][j], min(xy[i][m], xy[i+1][m])) + cost(x[i], z[j]);
            f[i][j] = find_k(i, j, ftp);
            //f[i][j], j > 1
            for(j = 2; j <= k; j++)
            {
                 ftp = min(f[i+1][j], min(f[i][j-1], f[i+1][j-1])) + cost(x[i], z[j]);
                 f[i][j] = find_k(i, j, ftp);
            }
       }
       printf("%d\n",f[1][k]);
    }
}
