#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int N=40010,M=2*N;
int E[N*2],L[N*2],R[N*2],ST[N*2][20];
int dis[N];
int fir[N],len[M],cnt,toV[M],nxt[M];
int n,m;
void init_graph()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
void addedge(int u,int v,int w)
{
     toV[cnt]=v,len[cnt]=w,nxt[cnt]=fir[u],fir[u]=cnt++;
}
int cc=1,vst[N];
void dfs(int r,int dep)
{
     vst[r]=1;
     if(!R[r]) R[r]=cc;
     E[cc]=r,L[cc++]=dep;
     for(int p=fir[r];p!=-1;p=nxt[p]) if(!vst[toV[p]])
     {
         dis[toV[p]]=dis[r]+len[p];
         dfs(toV[p],dep+1);
         E[cc]=r,L[cc++]=dep;
     }
}
void RMQ()
{
     for(int i=1;i<cc;i++) ST[i][0]=i;
     for(int s=1,j=1;s<cc;s<<=1,j++)
          for(int i=1;i+s<cc;i++)
               if(L[ST[i][j-1]]<L[ST[i+s][j-1]])
                     ST[i][j]=ST[i][j-1];
               else  ST[i][j]=ST[i+s][j-1];
          
}
int LCA(int u,int v)
{
    int a=R[u],b=R[v];
    if(a>b) swap(a,b);
    int k=(int)(log(b-a+1)/log(2));
    return min(ST[a][k],ST[a+(1<<k)][k]);
}
int main()
{
    scanf("%d%d",&n,&m);
    init_graph();
    for(int i=1;i<=m;i++)
    {
         int u,v,w;
         char dir[2];
         scanf("%d%d%d%s",&u,&v,&w,dir);
         addedge(u,v,w);
         addedge(v,u,w);
    }
    memset(vst,0,sizeof(vst));
    dfs(1,0);
    RMQ();
    int qq;
    scanf("%d",&qq);
    while(qq--)
    {
         int u,v;
         scanf("%d%d",&u,&v);
         printf("%d\n",dis[u]+dis[v]-2*dis[LCA(u,v)]);
    }
}
