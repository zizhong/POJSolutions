#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int N=10001,inf=0x3fffffff;
vector<int> g[N];
int v[N];
int f[N][3];
int _min(int a,int b){return a>b?b:a;}
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
         f[x][0]+=_min(f[cd[i]][1],f[cd[i]][2]);
     for(int i=0;i<nd;i++)
         f[x][1]+=_min(min(f[cd[i]][1],f[cd[i]][0]),f[cd[i]][2]);
     f[x][1]+=1;
     int min=inf;
     for(int i=0;i<nd;i++)
     {
         for(int j=0;j<nd;j++)
             if(i!=j) f[x][2]+=_min(f[cd[j]][2],f[cd[j]][1]);
             else f[x][2]+=f[cd[j]][1];
         if(min>f[x][2]) min=f[x][2];
         f[x][2]=0;
     }
     f[x][2]=min;
     return ;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
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
    
    /*for(int i=1;i<=n;i++)
        printf("%15d%15d%15d\n",f[i][0],f[i][1],f[i][2]);
    scanf("%'d");*/
}
