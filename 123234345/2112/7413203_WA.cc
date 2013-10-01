#include<stdio.h>
#include<string.h>
const int N=250,inf=0x3fffffff;
int k,c,m;
int g[N][N];
int map[N][N];
int Q[N],pre[N];
int max_flow(int s,int t)
{
    int p,q,u,v;
    int flow=0,aug;
    while(true)
    {
        memset(pre,-1,sizeof(pre));
        for(Q[p=q=0]=s;p<=q;p++)
        {
             u=Q[p];
             for(v=0;v<=k+c+1&&pre[t]<0;v++)
                 if(g[u][v]>0&&pre[v]<0)
                     pre[v]=u,Q[++q]=v;
             if(pre[t]>=0) break;
        }
        if(pre[t]<0) break;
        aug=inf;
        for(u=pre[v=t];v!=s;v=u,u=pre[u]) if(g[u][v]<aug) aug=g[u][v];
        for(u=pre[v=t];v!=s;v=u,u=pre[u])
              g[u][v]-=aug,g[v][u]+=aug;
        flow+=aug;
    }
    return flow;
}
int ok(int x)
{
    memset(g,0,sizeof(g));
    int n=k+c;
    for(int i=1;i<=k;i++)
        for(int j=k+1;j<=k+c;j++)
             if(map[j][i]<=x)g[j][i]=map[j][i];
    for(int i=k+1;i<=k+c;i++)
       g[0][i]=1;
    for(int i=1;i<=k;i++)
       g[i][n+1]=m;
    if(max_flow(0,n+1)==c) return 1;
}
int main()
{
    scanf("%d%d%d",&k,&c,&m);
    for(int i=1;i<=k+c;i++)
        for(int j=1;j<=k+c;j++)
        {
            scanf("%d",&map[i][j]);
            if(!map[i][j]) map[i][j]=inf;
        }
    for(int h=1;h<=k+c;h++)
       for(int i=1;i<=k+c;i++)
           for(int j=1;j<=k+c;j++)
                if(map[i][k]+map[k][j]<map[i][j])
                    map[i][j]=inf;
    int high=200,low=1,mid;
    while(low+1<high)
    {
        //printf("%d %d\n",low,high);
        mid=low+high>>1;
        if(ok(mid)) high=mid;
        else low=mid;
    }
    printf("%d\n",high);
    //scanf("%'d");
}
