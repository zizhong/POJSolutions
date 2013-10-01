#include<cstdio>
#include<cstring>
#include<cmath>
#define type double
const int inf=0x3fffffff,M=101*101;
struct Node
{
       int u,v;
       type cost;
       Node(int u1=0,int v1=0,type c1=0):u(u1),v(v1),cost(c1){};
}e[M];
int pre[M],id[M],vis[M];
type in[M];
type Directed_MST(int rt,int nv,int ne)
{
     type ret=0;
     while(true)
     {
         //1.find min in-edge
         for(int i=0;i<nv;i++) in[i]=inf;
         for(int i=0;i<ne;i++)
         {
              int u=e[i].u,v=e[i].v;
              if(e[i].cost<in[v] && u!=v )
                  pre[v]=u,in[v]=e[i].cost;
         }
         for(int i=0;i<nv;i++) 
              if(i!=rt && in[i]==inf) 
                     return -1;//unreachable:MST_NON_Exist
         //2.find circle
         int cntnode=0;
         memset(id,-1,sizeof(id));
         memset(vis,-1,sizeof(vis));
         in[rt]=0;
         for(int i=0;i<nv;i++)
         {
              ret+=in[i];
              int v=i;
              while(vis[v]!=i && id[v]==-1 && v!=rt)
                   vis[v]=i,v=pre[v];
              if(v!=rt && id[v]==-1)
              {
                   for(int u=pre[v];u!=v;u=pre[u])
                       id[u]=cntnode;
                   id[v]=cntnode++;
              }
         }
         if(cntnode == 0) break;//no circle
         for(int i=0;i<nv;i++) if(id[i]==-1)
              id[i]=cntnode++;
         for(int i=0;i<ne;i++)//3.shrink circle
         {
              int v=e[i].v;
              e[i].u=id[e[i].u];
              e[i].v=id[e[i].v];
              if(e[i].u!=e[i].v) e[i].cost-=in[v];
         }
         nv=cntnode;
         rt=id[rt];
     }
     return ret;
}
struct Point
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
}p[128];
double dis(Point &p1,Point &p2)
{
       return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
         for(int i=0;i<n;i++) p[i].init();
         for(int i=0;i<m;i++)
         {
             int u,v;
             scanf("%d%d",&u,&v);
             e[i]=Node(u-1,v-1,dis(p[u-1],p[v-1]));
         }
         double ans=Directed_MST(0,n,m);
         if(ans<0) puts("poor snoopy");
         else printf("%.2f\n",ans);
    }
}
