#include<stdio.h>
const int N=101,inf=10000000;
int g[N][N];
int pre[N][N],dis[N][N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            g[i][j]=inf;
    for(int i=0;i<m;i++)
    {
         int d,x,y;
         scanf("%d%d%d",&x,&y,&d);
         if(g[x][y]>d) g[x][y]=g[y][x]=d;
    }
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       {
            pre[i][j]=i;
            dis[i][j]=g[i][j];
       }
    int minc=inf;
    int path[N]={0},cnt=0;
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<k;i++)
           for(int j=i+1;j<k;j++)
              if(minc>dis[i][j]+g[i][k]+g[k][j])
              {
                   minc=dis[i][j]+g[i][k]+g[k][j];
                   int p=j;
                   cnt=0;
                   path[cnt++]=k;
                   while(p!=i)
                   {
                        path[cnt++]=p;
                        p=pre[i][p];
                   }
                   path[cnt++]=p;
              }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
               if(dis[i][j]>dis[i][k]+dis[k][j])
               {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    pre[i][j]=pre[k][j];
               }
        
    }
    if(minc==inf)
    {
         puts("No solution.");         
    }
    else
    {
        printf("%d\n",minc);
        for(int i=0;i<cnt;i++)
        {
            if(i) printf(" ");
            printf("%d",path[i]);
        }
        puts("");
    }
    //scanf("%'d");
}
