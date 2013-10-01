#include<stdio.h>
const int N=1001,inf=0xffffff;
int min(int a,int b){return a>b?b:a;}
int n,m,x;
void dij(int g[N][N],int d[])
{
     for(int i=0;i<=n;i++)
         d[i]=g[x][i];
     int v[N]={0};
     v[x]=1;
     while(1)
     {
          int min=inf,tail=-1;
          for(int i=1;i<=n;i++)
             if(!v[i]&&min>d[i])
                min=d[i],tail=i;
          if(tail==-1) break;
          v[tail]=1;
          for(int i=1;i<=n;i++)
             if(!v[i]&&d[i]>d[tail]+g[tail][i])
                 d[i]=d[tail]+g[tail][i];
     }
}
int g[N][N],g1[N][N];
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    int d[N],d1[N];
    for(int i=1;i<=n;i++)
       for(int j=1;j<=i;j++)
          g[i][j]=g[j][i]=g1[i][j]=g1[j][i]=inf;
    for(int i=0;i<m;i++)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        g[a][b]=g1[b][a]=min(g[a][b],t);
    }
    dij(g,d),dij(g1,d1);
    int ans=0;
    for(int i=1;i<=n;i++) if(i!=x&&d[i]+d1[i]>ans)
         ans=d[i]+d1[i];
    printf("%d\n",ans);
    scanf("%'d");
}
