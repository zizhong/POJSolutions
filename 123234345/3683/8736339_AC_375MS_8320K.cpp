#include<iostream>
#include<algorithm>
#include<vector>
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
void init()
{
     for(int i=0;i<N;i++) edge[i].clear();
     fill(&dfn[0],&dfn[N],-1);
     fill(&comp[0],&comp[N],-1);
     ncomp=dfstime=ss=0;
}
struct Wedding
{
       int s,e,t;
}wed[N];
bool intersect(int x1,int y1,int x2,int y2)
{
     return !(y1<=x2||y2<=x1);
}
int choose[N],pass[N],bro[N];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
          for(int i=0;i<n;i++)
          {
               int a,b;
               scanf("%2d:%2d",&a,&b);
               wed[i].s=a*60+b;
               scanf("%2d:%2d%d",&a,&b,&wed[i].t);
               wed[i].e=a*60+b;
          }
          init();
          for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
             {
                  int s1=wed[i].s,e1=wed[i].e,t1=wed[i].t,
                      s2=wed[j].s,e2=wed[j].e,t2=wed[j].t;
                  if(intersect(s1,s1+t1,s2,s2+t2))  add_or(i,1,j,1);//add_distinct(i,j);
                  if(intersect(s1,s1+t1,e2-t2,e2))  add_or(i,1,j,0);//add_equal(i,j);
                  if(intersect(e1-t1,e1,s2,s2+t2))  add_or(i,0,j,1);//add_equal(i,j);
                  if(intersect(e1-t1,e1,e2-t2,e2))  add_or(i,0,j,0);//add_distinct(i,j);  
             }
          for(int i=0;i<2*n;i++) if(dfn[i]<0) scc(i);
          bool possible=true;
          for(int i=0;possible && i<2*n;i+=2)
                 if(comp[i]==comp[i+1])
                        possible = false;
                 else bro[comp[i]]=comp[i+1],bro[comp[i+1]]=comp[i];
                 
          if(!possible) puts("NO");
          else
          {
              memset(choose,0,sizeof(choose));
              memset(pass,0,sizeof(pass));
              for(int i=0;i<ncomp;i++)
                   if(pass[i]==0) choose[i]=1,pass[bro[i]]=1;
                   
              puts("YES");
              
              for(int i=0;i<2*n;i++) if(choose[comp[i]])
              {
                   int s=wed[i>>1].s,e=wed[i>>1].e,t=wed[i>>1].t,x,y;
                   if(i&1) x=e-t,y=e;
                   else    x=s,y=s+t;
                   printf("%02d:%02d %02d:%02d\n",x/60,x%60,y/60,y%60);
              }
          }
    }
}
