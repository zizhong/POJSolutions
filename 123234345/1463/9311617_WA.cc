#include<cstdio>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
const int N=1521,inf=0x3fffffff;
vector<int> tr[N];
int mark[N],n,dp[N][2];
void dfs(int r)
{
     dp[r][1]=1;
     for(int i=0;i<tr[r].size();i++)
     {
          dfs(tr[r][i]);
          dp[r][0]+=dp[tr[r][i]][1];
          dp[r][1]+=min(dp[tr[r][i]][0],dp[tr[r][i]][1]);
     }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
          for(int i=0;i<n;i++)
          {
               tr[i].clear();
               int x,k,v;
               scanf("%d:(%d)",&x,&k);
               mark[x]=i;
               for(int j=0;j<k;j++)
               {
                   scanf("%d",&v);
                   tr[i].push_back(v);
               }
          }
          int in[N]={0};
          for(int i=0;i<n;i++)
             for(int j=0;j<tr[i].size();j++)
                  tr[i][j]=mark[tr[i][j]],in[tr[i][j]]++;
          int r=0;
          while(in[r]) r++;
          dfs(r);
          printf("%d\n",min(dp[r][0],dp[r][1]));
    }
}
