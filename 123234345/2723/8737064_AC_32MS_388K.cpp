#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=(1<<11)+10;
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
int key[N];
int con[N][2];
int n,m;
bool check(int x)
{
     init();
     for(int i=0;i<x;i++)
     {
          int a=key[con[i][0]],b=key[con[i][1]];
          add_or(a>>1,a&1,b>>1,b&1);
     }
     for(int i=0;i<n*2;i++) if(dfn[i]<0) scc(i);
     for(int i=0;i<2*n;i+=2) if(comp[i]==comp[i+1]) 
         return false;
     return true;
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        for(int i=0;i<2*n;i++)
        {
              int tmp;
              scanf("%d",&tmp);
              key[tmp]=i;
        }
        for(int i=0;i<m;i++)
             scanf("%d%d",&con[i][0],&con[i][1]);
        int l=0,r=m+1;
        while(l+1<r)
        {
             int mid=l+r>>1;
             if(check(mid)) l=mid;
             else r=mid;
        }
        printf("%d\n",l);
    }
}
