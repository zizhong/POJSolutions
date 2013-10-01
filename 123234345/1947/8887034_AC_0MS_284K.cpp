#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int N=152,inf=1000;
int f[N][N],sz[N];
vector<int>tree[N]; 
int n,p;
void dp(int cur,int fa)
{
     for(int i=0;i<tree[cur].size();i++) if(tree[cur][i]!=fa)
          dp(tree[cur][i],cur);
     f[cur][1]=tree[cur].size();
     for(int i=0;i<tree[cur].size();i++) if(tree[cur][i]!=fa)
     {
                for(int v=p;v>=1;v--) if(f[cur][v]<inf)
                for(int j=1;j<p;j++)  if(f[tree[cur][i]][j]<inf)
                {
                      if(v+j<=p && f[cur][v+j]>f[cur][v]+f[tree[cur][i]][j]-1)
                          f[cur][v+j]=f[cur][v]+f[tree[cur][i]][j]-1;
                }
     }
}
int main()
{
   
    while(scanf("%d%d",&n,&p)==2)
    {
         for(int i=0;i<n;i++) tree[i].clear();
         for(int i=0;i<n;i++)
            for(int j=1;j<n;j++)
                f[i][j]=inf;
         for(int i=0;i<n-1;i++)
         {
             int u,v;
             scanf("%d%d",&u,&v);
             --u,--v;
             tree[u].push_back(v);
         }
         int t;
         dp(0,0);
         f[0][n]=0;
         int ans=inf;
         for(int i=1;i<n;i++)
             if(ans>f[i][p]+1) ans=f[i][p]+1;
         if(ans>f[0][p]) ans=f[0][p];
         printf("%d\n",ans);
    }
}
