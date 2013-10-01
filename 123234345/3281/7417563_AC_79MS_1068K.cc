#include<stdio.h>
#include<string.h>
const int N=450;
int g[N][N];
int Q[N],pre[N];
int max_flow(int s,int t,int nn)
{
    int p,q,u,v;
    int flow=0,aug;
    while(true)
    {
        memset(pre,-1,sizeof(pre));
        for(Q[p=q=0]=s;p<=q;p++)
        {
             u=Q[p];
             for(v=0;v<=nn&&pre[t]<0;v++)
                 if(g[u][v]>0&&pre[v]<0)
                     pre[v]=u,Q[++q]=v;
             if(pre[t]>=0) break;
        }
        if(pre[t]<0) break;
        aug=N;
        for(u=pre[v=t];v!=s;v=u,u=pre[u]) if(g[u][v]<aug) aug=g[u][v];
        for(u=pre[v=t];v!=s;v=u,u=pre[u])
              g[u][v]-=aug,g[v][u]+=aug;
        flow+=aug;
    }
    return flow;
}

int main()
{
    int n,f,d;
    scanf("%d%d%d",&n,&f,&d);
    int s=0,t=f+d+2*n+1;
    for(int i=1;i<=f;i++)
         g[s][i]=1;
    for(int i=f+1;i<=f+d;i++)
         g[i][t]=1;
    for(int k=1;k<=n;k++)
    {
         int x,y,tmp;
         scanf("%d%d",&x,&y);
         while(x--)
         {
             scanf("%d",&tmp);
             g[tmp][f+d+k]=1;
         }
         while(y--)
         {
             scanf("%d",&tmp);
             g[f+d+n+k][f+tmp]=1;
         }
         g[f+d+k][f+d+n+k]=1;
    }
    printf("%d\n",max_flow(s,t,t));
}
