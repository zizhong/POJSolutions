#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N=10001,inf=0x3fffffff;
vector<int> g[N];
int v[N];
int f[N][3];
void dfs(int x)
{
     if(v[x]) return ;
     v[x]=1;
     int leaf=1;
     int n=g[x].size();
     vector<int> cd;
     for(int i=0;i<n;i++)
        if(v[g[x][i]]==0) cd.push_back(g[x][i]),leaf=0,dfs(g[x][i]);
     if(leaf==1)
     {
          f[x][1]=1;
          f[x][2]=inf;
          return ; 
     }
     int nd=cd.size();
     for(int i=0;i<nd;i++)
         f[x][0]+=min(f[cd[i]][1],f[cd[i]][2]);
     for(int i=0;i<nd;i++)
         f[x][1]+=min(min(f[cd[i]][0],f[cd[i]][1]),f[cd[i]][2]);
     f[x][1]+=1;
     int flag=1,min=inf;
     for(int i=0;i<nd;i++)
     {
         if(f[cd[i]][1]<=f[cd[i]][2])
         {
             flag=0;
             f[x][2]+=f[cd[i]][1];
         }
         else
         {
             if(min>f[cd[i]][1]-f[cd[i]][0])
                min=f[cd[i]][1]-f[cd[i]][0];
                f[x][2]+=f[cd[i]][2];
         }
     }
     if(flag) f[x][2]+=min;
     return ;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
         int x,y;
         scanf("%d%d",&x,&y);
         g[x].push_back(y);
         g[y].push_back(x);
    }
    dfs(1);
    int ans=inf;
    if(ans>f[1][1]) ans=f[1][1];
    if(ans>f[1][2]) ans=f[1][2];
    printf("%d\n",ans);
    
}
