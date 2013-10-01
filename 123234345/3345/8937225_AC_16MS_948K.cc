#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
const int N=210,inf=0x3fffffff;
int n,m,dia[N];
vector<string> child_name[N];
vector<int>    child[N];
string name[N];
char s[50000];

int use[N];
int f[N][N];
int after[N];
int p[N],q[N];
int dfs(int x)
{
    int ret = 0;
    if (use[x]) return after[x];
    for (int i = 0; i < child[x].size(); i++)
        ret += dfs(child[x][i]);
    
    for (int i = 0; i <= n; i++) p[i] = inf;
    p[0] = 0;
    for (int i = 0; i < child[x].size(); i++)
    {
        for (int j = 0; j <= n; j++) q[j] = inf;
        for (int k = 0; k <=n; k++) if (p[k] != inf)
        {
            for (int j = 0; k + j <= n; j++) if (f[child[x][i]][j] != inf)
                q[k + j] = min(p[k] + f[child[x][i]][j],q[k+j]);
        }
        for (int j = 0; j <= n; j++) p[j] =min(p[j] , q[j]);
    }
    use[x] = 1;
    after[x] = ret + 1;
    p[after[x]] = min(dia[x],p[after[x]]);
    memcpy(f[x], p, sizeof(p));
    
    return after[x];
}
int main()
{
    while(gets(s),s[0]!='#')
    {
          if(s[0]=='\0') continue;
          sscanf(s,"%d%d",&n,&m);
          for(int i=0;i<n;i++)
          {
                child_name[i].clear();
                child[i].clear();
                char str[128];
                scanf("%s%d",str,&dia[i]);
                name[i]=str;
                gets(s);
                stringstream ss(s);
                string t;
                while(ss>>t)
                       child_name[i].push_back(t);
          }
          int in_deg[N]={0};
          for(int i=0;i<n;i++)
               for(int j=0;j<child_name[i].size();j++)
                     for(int k=0;k<n;k++) if(child_name[i][j]==name[k])
                     {
                          child[i].push_back(k);
                          in_deg[k]++;
                          break;
                     }
          memset(use,0,sizeof(use));
          child[n].clear();
          dia[n]=inf;
          for(int i=0;i<n;i++) if(in_deg[i]==0) child[n].push_back(i);
          dfs(n);
          int ans=inf;
          for(int i=m;i<=n;i++) ans=min(ans,f[n][i]);
          printf("%d\n",ans);
    }
} 
