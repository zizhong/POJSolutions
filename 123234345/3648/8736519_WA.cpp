#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100;
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

int choose[N],pass[N],bro[N];

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&n)
    {
         n--;
         init();
         for(int i=0;i<m;i++)
         {
              int a,b;
              char v1,v2;
              scanf("%d%c%d%c",&a,&v1,&b,&v2);
              add_or(a,v1=='w',b,v2=='w');
         }
         for(int i=2;i<=2*n;i++) if(dfn[i]<0) scc(i);
         bool flag=true;
         for(int i=2;flag&&i<=2*n;i+=2) if(comp[i]==comp[i+1])
             flag=false;
         else bro[comp[i]]=comp[i+1],bro[comp[i+1]]=comp[i];
         if(!flag) puts("bad luck");
         else
         {
             memset(choose,0,sizeof(choose));
             memset(pass,0,sizeof(pass));
             for(int i=0;i<ncomp;i++) if(pass[i]==0)
                  choose[i]=1,pass[bro[i]]=1;
             for(int i=2;i<=2*n;i++) if(choose[comp[i]])
             {
                   if(i/2>1) putchar(' ');
                   printf("%d",i/2);  
                   putchar(i&1?'w':'h');
             }
             puts("");
         }
    }
}
