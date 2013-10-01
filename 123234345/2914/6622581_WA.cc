#include<stdio.h>
#include<string.h>
const int N = 502,INF=0xffffff;
int n,m;
int c[N][N];
int maxflow(int s,int t)
{
    int head,tail,q[N],u,v,pre[N];
    int flow=0,aug;
    while(true)
    {
         memset(pre,-1,sizeof(pre));
         for(q[head=tail=0]=s;head<=tail;head++)
         {
               u=q[head];
               for(v=0;v<n&&pre[t]<0;v++) if(c[u][v]>0&&pre[v]<0)
                   pre[v]=u,q[++tail]=v;
               if(pre[t]>=0) break;               
         }
         if(pre[t]<0) break;
         aug=INF;
         for(u=pre[v=t];v!=s;v=u,u=pre[u]) if(c[u][v]<aug) aug=c[u][v];
         for(u=pre[v=t];v!=s;v=u,u=pre[u]) c[u][v]-=aug,c[v][u]+=aug;
         flow+=aug;
    }
    return flow;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         memset(c,0,sizeof(c));
         int a,b,w;
         for(int i=0;i<m;i++)
         {
              scanf("%d%d%d",&a,&b,&w);
              c[a][b]+=w;
              c[b][a]=c[a][b];
         }
         printf("%d\n",maxflow(0,n-1));
    }
}
