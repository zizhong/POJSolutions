#include<stdio.h>
const int N=610,inf=100000000;
int g[N][N],a[N][N],b[N][N];
int n,m,na,nb,ca[N],cb[N];
int da[N],db[N];
void dijkstra(int n,int *d,int g1[N][N])
{     
     int v[N]={0};
     for(int i=1;i<=n;i++) d[i]=g1[1][i];
     d[1]=0,v[1]=1;
     while(1)
     {
           int min=inf,tail=-1;
           for(int i=1;i<=n;i++)
               if(!v[i]&&min>d[i])
                     min=d[i],tail=i;
           if(min==inf) break;
           v[tail]=1;
           for(int i=1;i<=n;i++)
                if(!v[i]&&d[i]>d[tail]+g1[tail][i])
                      d[i]=d[tail]+g1[tail][i];
     }
}
int main()
{
    while(scanf("%d",&n),n)
    {
         scanf("%d",&m);
         for(int i=0;i<=n;i++)
              for(int j=0;j<=n;j++)
                 if(i-j)  a[i][j]=b[i][j]=g[i][j]=inf;
         for(int i=0;i<m;i++)
         {
              int x,y,t;
              scanf("%d%d%d",&x,&y,&t);
              g[x][y]=g[y][x]=t;
         }
         na=nb=0;
         for(int i=1;i<=n;i++)
         {
              int x=0;
              scanf("%d",&x);
              x==1?ca[++na]=i:cb[++nb]=i;
         }
         for(int i=1;i<=na;i++)
             for(int j=1;j<=na;j++)
                 a[j][i]=a[i][j]=g[ca[i]][ca[j]];
         for(int i=1;i<=nb;i++)
             for(int j=1;j<=nb;j++)
                 b[j][i]=b[i][j]=g[cb[i]][cb[j]];
         dijkstra(na,da,a);
         dijkstra(nb,db,b);
         int ans=inf;
         for(int i=1;i<=na;i++)
             for(int j=1;j<=nb;j++)
                 if(ans>da[i]+g[ca[i]][cb[j]]+db[j])
                       ans=da[i]+g[ca[i]][cb[j]]+db[j];
         ans<inf?printf("%d\n",ans):puts("-1");
    }
}
