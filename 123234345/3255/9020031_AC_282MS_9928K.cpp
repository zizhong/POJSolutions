#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=5010,M=100000*2,inf=0x3fffffff;
int fir[N],nxt[M],len[M],e[M],cnt;
void init()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
int nv,ne;
void addedge(int u,int v,int w)
{
     e[cnt]=v,len[cnt]=w,nxt[cnt]=fir[u],fir[u]=cnt++;
}
struct Node1
{
       int v,c;
       Node1(int vv=0,int cc=0):v(vv),c(cc){}
       bool operator <(const Node1& b)const {return c>b.c;}
};
int dis[N],vst[N];
void dijkstra(int n,int src)
{
     priority_queue<Node1> q1;
     for(int i=1;i<=n;i++) dis[src]=0x3fffffff,vst[i]=0;
     vst[src]=1,dis[src]=0;
     q1.push(Node1(src,0));
     int pre=src;
     for(int i=1;i<=n;i++)
     {
          for(int j=fir[pre];j!=-1;j=nxt[j])
          {
               int k=e[j];
               if(vst[k]==0 && dis[k]>dis[pre]+len[j])
                     dis[k]=dis[pre]+len[j],q1.push(Node1(k,dis[k]));
          }
          while(!q1.empty() && vst[q1.top().v]) q1.pop();
          if(q1.empty()) break;
          vst[pre = q1.top().v]=1;
          q1.pop();
     }
}
struct Node2
{
       int g,h,v;
       Node2(int gg=0,int hh=0,int vv=0):g(gg),h(hh),v(vv){}
};
bool operator<(const Node2&a,const Node2&b)
{
	return a.g+a.h>b.g+b.h;
};
void Astar(int s,int t,int k)
{
     priority_queue<Node2> q2;
     int ct[N]={0};
     q2.push(Node2(0,dis[s],s));
     while(!q2.empty())
     {
          Node2 cur=q2.top();
          q2.pop();
          ct[cur.v]++;
          if(ct[t]==k) {printf("%d\n",cur.g+cur.h);return ;}
          if(ct[cur.v]>k) continue;
          for(int j=fir[cur.v];j!=-1;j=nxt[j])
               q2.push(Node2(cur.g+len[j],dis[e[j]],e[j]));
     }
}
int main()
{
    init();
    scanf("%d%d",&nv,&ne);
    for(int i=0;i<ne;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    dijkstra(nv,nv);
    Astar(1,nv,2);}
