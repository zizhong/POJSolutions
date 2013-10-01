#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=312,inf=0x3fffffff;
int n,m,t,g[N][N];
int main()
{
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
             if(i!=j) g[i][j]=inf;
    for(int i=0;i<m;i++)
    {
         int u,v,h;
         scanf("%d%d%d",&u,&v,&h);
         if(g[u][v]>h) g[u][v]=h;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(g[i][k]!=inf)
            for(int j=1;j<=n;j++) if(g[k][j]!=inf)
            {
                 int tmp=max(g[i][k],g[k][j]);
                 if(tmp<g[i][j]) g[i][j]=tmp;
            }
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(g[a][b]<inf) printf("%d\n",g[a][b]);
        else puts("-1");
    }
}
