#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int M=30010,N=15010;
struct Edge
{
     int u,v,w;
     Edge(int a=0,int b=0,int c=0): u(a), v(b), w(c){};
}g[M];
int d[N],n,m;
void Bellman()
{
     for(int i=1;i<n;i++) d[i]=0;d[n]=0x3fffffff;
     while(1)
     {
         int flag=1;
         for(int i=0;i<m;i++)
              if(d[g[i].v]<d[g[i].u]+g[i].w)
              {
                   flag=0;
                   d[g[i].v]=d[g[i].u]+g[i].w;
              }
         if(flag) break;
     }
     //for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
     int ans=abs(d[1]-d[n]);
     for(int i=1;i<n;i++) d[i]=0;d[n]=-0x3fffffff;
     while(1)
     {
         int flag=1;
         for(int i=0;i<m;i++)
              if(d[g[i].v]<d[g[i].u]+g[i].w)
              {
                   flag=0;
                   d[g[i].v]=d[g[i].u]+g[i].w;
              }
         if(flag) break;
     }
     ans=max(ans,abs(d[1]-d[n]));
     printf("%d\n",ans);
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
         int u,v,w;
         for(int i=0;i<m;i++)
         {
             scanf("%d%d%d",&u,&v,&w);
             g[i]=Edge(u,v,-w);
         }
         Bellman();
    }
} 
