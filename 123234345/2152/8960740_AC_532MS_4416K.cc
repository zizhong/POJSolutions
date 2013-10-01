#include<cstring>
#include<cstdio>
const int N=1010,M=4*N,inf=0x3fffffff;
int n,w[N],d[N];
int fir[N],e[M],nxt[M],len[M],cnt;
int min(int a,int b){return a>b?b:a;}
void init()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
void addedge(int u,int v,int l)
{
     e[cnt]=v,len[cnt]=l,nxt[cnt]=fir[u];
     fir[u]=cnt++;
}
int f[N][N],dis[N],best[N];
void calDis(int x)
{
     for(int p=fir[x];p!=-1;p=nxt[p]) if(dis[e[p]]==-1)
     {
          dis[e[p]]=dis[x]+len[p];
          calDis(e[p]);
     }
}
void dp(int x,int pre)
{
     for(int p=fir[x];p!=-1;p=nxt[p]) if(e[p]!=pre)
         dp(e[p],x);
     memset(dis,-1,sizeof(dis));
     dis[x]=0;
     calDis(x);
     best[x]=inf;
     for(int i=1;i<=n;i++) if(dis[i]<=d[x])
     {
          f[x][i]=w[i];
          for(int p=fir[x];p!=-1;p=nxt[p]) if(e[p]!=pre)
               f[x][i]+=min(best[e[p]],f[e[p]][i]-w[i]);
          if(best[x]>f[x][i]) best[x]=f[x][i];
     }else f[x][i]=inf;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         init();
         scanf("%d",&n);
         for(int i=1;i<=n;i++) scanf("%d",&w[i]);
         for(int i=1;i<=n;i++) scanf("%d",&d[i]);
         for(int i=0;i<n-1;i++)
         {
              int u,v,l;
              scanf("%d%d%d",&u,&v,&l);
              addedge(u,v,l);
              addedge(v,u,l);
         }
         dp(1,0);
         printf("%d\n",best[1]);
    }
}
