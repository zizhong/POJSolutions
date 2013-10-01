#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
const int N=152,inf=1000;
int f[N][N],sz[N];
vector<int>tree[N]; 
int n,p;
void dp(int cur,int fa,int &num)
{
     num=1;
     bool leaf=true;
     for(int i=0;i<tree[cur].size();i++) if(tree[cur][i]!=fa)
     {
          leaf=false;
          int t;
          dp(tree[cur][i],cur,t);
          num+=t;
     }
     sz[cur]=num;
     for(int i=0;i<tree[cur].size();i++) if(tree[cur][i]!=fa)
     {
          for(int j=1;j<=sz[tree[cur][i]];j++)
          {
                for(int v=p;v>=0;v--)
                {
                      if(v+j<=p && f[cur][v+j]>f[cur][v]+f[tree[cur][i]][j])
                          f[cur][v+j]=f[cur][v]+f[tree[cur][i]][j];
                }
          }
     }
     f[cur][num]=1;
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
             tree[u].push_back(v),tree[v].push_back(u);
         }
         int t;
         dp(0,0,t);
         f[0][n]=0;
         int ans=inf;
         for(int i=0;i<n;i++)
             if(ans>f[i][p]) ans=f[i][p];
         if(ans>f[0][n-p]) ans=f[0][n-p];
         printf("%d\n",ans);
    }
}
