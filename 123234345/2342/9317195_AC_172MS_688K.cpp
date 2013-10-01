#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
const int N=6010;
int n,d[N],f[N][2];
vector<int >tr[N];
void dfs(int r)
{
    f[r][0]=0;
    f[r][1]=d[r];
    for(int i=0;i<tr[r].size();i++)
    {
         dfs(tr[r][i]);
         f[r][0]+=max(f[tr[r][i]][0],f[tr[r][i]][1]);
         f[r][1]+=f[tr[r][i]][0];
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
          for(int i=1;i<=n;i++) tr[i].clear();
          for(int i=1;i<=n;i++)
                 scanf("%d",&d[i]);
          int in[N]={0};
          for(int i=0;i<n-1;i++)
          {
             int u,v;
             scanf("%d%d",&u,&v);
             tr[v].push_back(u);
             in[u]++;
          }
          int r=1;
          while(in[r]) r++;
          dfs(r);
          printf("%d\n",max(f[r][0],f[r][1]));
    }
}
