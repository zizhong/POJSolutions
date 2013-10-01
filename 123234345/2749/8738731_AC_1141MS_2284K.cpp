#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1010;
vector<int>edge[N];
void set(int i,int val)
{
     int must=(i<<1)|val;
     edge[must^1].push_back(must);
}
void add_or(int i,int v1,int j,int v2)
{
     edge[(i<<1)|(v1^1)].push_back((j<<1)|v2);
     edge[(j<<1)|(v2^1)].push_back((i<<1)|v1);
}
void add_equal(int i,int j)
{
     add_or(i,1,j,0);
     add_or(i,0,j,1);
}
void add_distinct(int i,int j)
{
     add_or(i,0,j,0);
     add_or(i,1,j,1);     
}

//Tarjan's algorithm for strongly connected components.
int dfstime,dfn[N],low[N],ncomp,comp[N],stack[N],ss;
void scc(int v)
{
     int w;
     dfn[v]=dfstime;
     low[v]=dfstime++;
     stack[ss++]=v;
     for(int i=0;i<edge[v].size();++i)
     {
          int w=edge[v][i];
          if(dfn[w]<0) {scc(w);low[v]=min(low[v],low[w]); }
          else if(comp[w]<0) low[v]=min(low[v],dfn[w]);
     }
     if(dfn[v]==low[v])
     {
           do
           {
               w=stack[--ss];
               comp[w]=ncomp;        
           }while(w!=v);
           ++ncomp;
     }
}
void init()
{
     for(int i=0;i<N;i++) edge[i].clear();
     fill(&dfn[0],&dfn[N],-1);
     fill(&comp[0],&comp[N],-1);
     ncomp=dfstime=ss=0;
}


int fd[N][2],ey[N][2],n,A,B;
struct Point
{
       int x,y;
       void read(){scanf("%d%d",&x,&y);}
}barn[501],s1,s2;
int dist(Point p1,Point p2)
{
    return abs(p1.x-p2.x)+abs(p1.y-p2.y);
}
bool check(int x)
{
     init();
     for(int i=0;i<A;i++) add_distinct(ey[i][0]-1,ey[i][1]-1);
     for(int i=0;i<B;i++) add_equal(fd[i][0]-1,fd[i][1]-1);
     for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
             if(dist(barn[i],s1)+dist(barn[j],s1)>x) add_or(i,1,j,1);
             if(dist(barn[i],s2)+dist(barn[j],s2)>x) add_or(i,0,j,0);
             if(dist(barn[i],s1)+dist(s1,s2)+dist(barn[j],s2)>x) add_or(i,1,j,0);
             if(dist(barn[i],s2)+dist(s1,s2)+dist(barn[j],s1)>x) add_or(i,0,j,1); 
        }
     for(int i=0;i<2*n;i++) if(dfn[i]<0) scc(i);
     for(int i=0;i<2*n;i+=2) if(comp[i]==comp[i+1]) 
          return false;
     return true;
}
int main()
{
    while(scanf("%d%d%d",&n,&A,&B)==3)
    {
         s1.read(),s2.read();
         for(int i=0;i<n;i++) barn[i].read();
         for(int i=0;i<A;i++) scanf("%d%d",&ey[i][0],&ey[i][1]);
         for(int i=0;i<B;i++) scanf("%d%d",&fd[i][0],&fd[i][1]);
         long long l=0,r=0x7ffffffe;
         while(l+1<r)
         {
             int mid=(l+r)/2;
             if(check(mid)) r=mid;
             else l=mid;
         }
         if(r==0x7ffffffe) puts("-1");
         else  printf("%lld\n",r);
    }
}
