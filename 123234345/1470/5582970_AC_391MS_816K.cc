#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
#define clr(x) memset(x,0,sizeof(x))
const int MAXN=905;
int E[2*MAXN];
int R[MAXN];
int L[2*MAXN];
int d[2*MAXN][12];
vector<int >tree[MAXN];
int tot,visited[MAXN];
void create_table()
{
     for(int j=0;(1<<j)<=tot;j++)
        for(int i=0;i+(1<<j)<=tot;i++)
        {
            if(j==0) d[i][j]=i;
            else
            {
                if(L[d[i][j-1]]<L[d[i+(1<<(j-1))][j-1]])
                   d[i][j]=d[i][j-1];
                else
                   d[i][j]=d[i+(1<<(j-1))][j-1];
            }
        }
}
void DFS(int u,int deep)
{
     if(!visited[u])
     {
          visited[u]=1;
          R[u]=tot;
     }
     E[tot]=u;
     L[tot++]=deep;
     vector<int>::size_type ix,size=tree[u].size();
     for(ix=0;ix!=size;ix++)
     {
         DFS(tree[u][ix],deep+1);
         E[tot]=u;
         L[tot++]=deep;
     }
}
int RMQ(int v1,int v2)
{
    int k=0;
    while((1<<(k+1))<(v2-v1+1)) 
        k++;
    if(L[d[v1][k]]<L[d[v2-(1<<k)+1][k]])
        return E[d[v1][k]];
    else
        return E[d[v2-(1<<k)+1][k]];
}
int LCA(int v1,int v2)
{
    if(R[v1]<R[v2])
        return RMQ(R[v1],R[v2]);
    else
        return RMQ(R[v2],R[v1]);
}

int main()
{
    char ch;
    int i,j,u,v,m,n,q;
    int in_deg[MAXN],count[MAXN];
    while(scanf("%d",&n)!=EOF)
    {
         for(i=0;i<n;i++)
             tree[i].clear();
         clr(in_deg);
         for(i=0;i<n;i++)
         {
             scanf("%d",&u);
             while((ch=getchar())!='(') ;
             scanf("%d",&m);
             while((ch=getchar())!=')') ;
             for(j=0;j<m;j++)
             {
                 scanf("%d",&v);
                 tree[u-1].push_back(v-1);
                 in_deg[v-1]++;
             }
         }
         int root=-1;
         for(i=0;i<n;i++)
            if(in_deg[i]==0)
            {
                root=i;
                break;
            }
         tot=0;
         clr(visited);
         DFS(root,0);
         create_table();
         scanf("%d",&q);
         clr(count);
         while(q--)
         {
              while((ch=getchar())!='(') ;
              scanf("%d %d",&u,&v);
              count[LCA(--u,--v)]++;
              while((ch=getchar())!=')') ;
         }
         for(i=0;i<n;i++)
         {
             if(count[i]>0)
                 printf("%d:%d\n",i+1,count[i]);
         }
    }
}