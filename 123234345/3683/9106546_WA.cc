#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int N=510;
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
const int M=10010;
int n,m;
int a[M],b[M],c[M];
bool ok(int x)
{
     init();
     for(int i=1;i<=x;i++)
     {
          switch(c[i])
          {
               case 0:add_or(a[i],1,b[i],1);break;
               case 1:add_equal(a[i],b[i]);break;
               case 2:add_or(a[i],0,b[i],0);               
          }
     }
     for(int i=0;i<2*n;i++) if(dfn[i]<0) scc(i);
     bool possible=true;
     for(int i=0;i<2*n;i+=2) if(comp[i]==comp[i+1]) possible=false;
     return possible;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {         
         scanf("%d%d",&n,&m);
         for(int i=1;i<=m;i++)
                scanf("%d%d%d",&a[i],&b[i],&c[i]);
         int l=1,r=m+1;
         while(l+1<r)
         {
              int mid=l+r>>1;
              if(ok(mid)) l=mid;
              else r=mid;
         }
         printf("%d\n",l);
    }
}

