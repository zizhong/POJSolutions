#include<cstdio>
#include<vector>
using namespace std;
vector<int> tr[10010];
vector<int> vst[10010];
int n,m;
void dfs(int r)
{
     for(int i=0;i<tr[r].size();i++) if(!vst[r][i])
     {
          vst[r][i]=1;
          dfs(tr[r][i]);
     }
     printf("%d\n",r);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
          int u,v;
          scanf("%d%d",&u,&v);
          tr[u].push_back(v);
          tr[v].push_back(u);
          vst[u].push_back(0);
          vst[v].push_back(0);
    }
    dfs(1);
    scanf("%'d");
}
