#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1024,inf=0x3fffffff;
int g[N][N];
int n,p,k;
bool ok(int x)
{
     int d[N],vst[N];
     for(int i=1;i<=n;i++)
     {
         d[i]=(g[1][i]>x);
         if(g[1][i]==inf) d[i]=inf;
         vst[i]=0;
     }
     d[1]=0,vst[1]=1;
     while(true)
     {
          int min=inf,tail=-1;
          for(int i=1;i<=n;i++) 
              if(vst[i]==0 && min>d[i])
                  min=d[i],tail=i;
          if(tail==-1) break;
          vst[tail]=1;
          for(int i=1;i<=n;i++)
              if(vst[i]==0 && g[tail][i]<inf&& d[tail] + (g[tail][i]>x) < d[i])
                   d[i]=d[tail]+(g[tail][i]>x);
     }
     return d[n]<=k;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           if(i!=j) g[i][j]=inf;
    for(int i=0;i<p;i++)
    {
         int u,v,w;
         scanf("%d%d%d",&u,&v,&w);
         g[u][v]=g[v][u]=min(g[u][v],w);
    }
    int l=0,r=inf;
    if(!ok(r)) puts("-1");
    else if(ok(l)) puts("0");
    else
    {
        while(l+1<r)
        {
            int mid=l+r>>1;
            if(ok(mid)) r=mid;
            else l=mid;
        }
        printf("%d\n",r);
    }
}
