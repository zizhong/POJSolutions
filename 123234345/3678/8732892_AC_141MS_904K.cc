#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

const int N=2010;
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
int n;
void init()
{
     for(int i=0;i<n;i++) edge[i].clear();
     fill(&dfn[0],&dfn[n],-1);
     fill(&comp[0],&comp[n],-1);
     ncomp=dfstime=ss=0;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)==2)
    {
         n<<=1;
         init();
         for(int i=0;i<m;i++)
         {
              int x1,x2,r;
              char tmp[4];
              scanf("%d%d%d%s",&x1,&x2,&r,tmp);
              switch(tmp[0])
              {
                   case 'A':
                        if(r) set(x1,1),set(x2,1);
                        else add_or(x1,0,x2,0);
                        break;
                   case 'O':
                        if(r) add_or(x1,1,x2,1);
                        else set(x1,0),set(x2,0);
                        break;
                   case 'X':
                        if(!r) add_equal(x1,x2);
                        else add_distinct(x1,x2);
              }
         }
         for(int i=0;i<n;i++) if(dfn[i]<0) scc(i);
         bool possible=true;
         for(int i=0;possible && i<n;i+=2)
              if(comp[i]==comp[i+1]) possible=false;
         puts(possible?"YES":"NO");
            
    }
}