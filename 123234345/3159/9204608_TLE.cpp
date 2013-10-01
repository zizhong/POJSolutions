#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int M=30010,N=15010,inf=0x3fffffff;
struct Edge
{
     int u,v,w;
     Edge(int a=0,int b=0,int c=0): u(a), v(b), w(c){};
}g[M];
int d[N],n,m;
void Bellman()
{
     for(int i=1;i<=n;i++) d[i]=inf;
     d[1]=0;
     while(1)
     {
         int flag=1;
         for(int i=0;i<m;i++)
              if(d[g[i].v]>d[g[i].u]+g[i].w)
              {
                   flag=0;
                   d[g[i].v]=d[g[i].u]+g[i].w;
              }
         if(flag) break;
     }
     //for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
     printf("%d\n",d[n]-d[1]);
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
         int u,v,w;
         for(int i=0;i<m;i++)
         {
             scanf("%d%d%d",&u,&v,&w);
             g[i]=Edge(u,v,w);
         }
         Bellman();
    }
} 
