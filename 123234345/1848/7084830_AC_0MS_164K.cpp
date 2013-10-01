#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int INF=1000;
int f[105][3];
vector<int> v[105];
int n;
void dfs(int r,int fa)
{
     bool lf=true;
     f[r][0]=f[r][2]=INF;
     f[r][1]=0;
     for(int i=0;i<v[r].size();++i)
     {
         if(v[r][i]==fa) continue;
         lf=false;
         dfs(v[r][i],r);
         f[r][1]+=f[v[r][i]][0];
     }
     if(lf) return ;
     for(int i=0;i<v[r].size();++i)
     {
         if(v[r][i]==fa) continue;
         f[r][0]=min(f[r][0],f[r][1]-f[v[r][i]][0]+f[v[r][i]][2]+1);
         f[r][2]=min(f[r][2],f[r][1]-f[v[r][i]][0]+min(f[v[r][i]][1],f[v[r][i]][2]));
         for(int j=i+1;j<v[r].size();++j)
         {
             if(v[r][j]==fa) continue;
             f[r][0]= min(f[r][0],f[r][1]-f[v[r][i]][0]-f[v[r][j]][0]
                      +min(f[v[r][i]][2],f[v[r][i]][1])+min(f[v[r][j]][2],f[v[r][j]][1])+1);
         } 
     }
}
int main()
{
    int a,b;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i)
    {
          scanf("%d%d",&a,&b);
          v[a].push_back(b);
          v[b].push_back(a);
    }
    dfs(1,0);
    printf("%d\n",f[1][0]>=INF?-1:f[1][0]);
}
