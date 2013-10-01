#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;
int dnf[4450],low[4450],cnt;
int fmax;
bool g[4450][4450],mark[4450],block_no[4450],ans;
stack<int> s;
int n,m;
void dfs(int u,int fa)
{
  low[u]=dnf[u]=++cnt;
  s.push(u);
  block_no[u]=ans;
  for(int v=1;v<=n;v++)
  {
    if(!g[u][v]||mark[v])
      continue;
    if(dnf[v]==-1)
    {
      dfs(v,u);
      if(dnf[u]<=low[v])
      {
        ans++;
        int num=0;
        while(1)
        {
          int temp=s.top();
          block_no[temp]=ans;
          num++;
          mark[temp]=1;
          s.pop(); 
          if(temp==v)
            break; 
      
        }
        num++;
        if(num>fmax&&num>2)
          fmax=num;
      }
      low[u]=low[u]<low[v]?low[u]:low[v];              
    }        
    else if(v!=fa)
      low[u]=low[u]<dnf[v]?low[u]:dnf[v];
  }
  return ;
}

int main()
{
  int t;
  int u,v;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&m);
    fmax=0;
    cnt=0;
    memset(g,0,sizeof(g));
    memset(mark,0,sizeof(mark));
    memset(dnf,-1,sizeof(dnf));
    memset(low,-1,sizeof(low));
    ans=0;
    while(!s.empty())
      s.pop();
    for(int i=0;i<m;i++)
    {
      scanf("%d %d",&u,&v);
      g[u][v]=g[v][u]=1;        
    }    
    for(int i=1;i<=n;i++)
      if(!mark[i])    
        dfs(i,-1);  
    printf("%d\n",fmax);
  }    
}