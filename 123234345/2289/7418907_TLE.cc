#include<stdio.h>
#include<string.h>
const int N=1515;
int n,m;
int g[N][N];
int map[N][N],s,t;
int Q[N],pre[N];
int max_flow(int nn)
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

int ok(int x)
{
    for(int i=0;i<=n+m+1;i++)
       for(int j=0;j<=n+m+1;j++)
           g[i][j]=map[i][j];
    for(int i=n+1;i<=n+m;i++)
        g[i][t]=x;
    return max_flow(n+m+1)==n;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d",&n,&m),n)
    {
          memset(map,0,sizeof(map));
          s=0,t=n+m+1;
          getchar();
          for(int i=1;i<=n;i++)
          {
               char c;
               int f1=0,d=0;
               char s[1024];
               gets(s);
               for(int j=0;s[j];j++)
               {
                    c=s[j];
                    if(!(c>='0'&&c<='9'))
                    {
                          if(f1)
                          {
                              map[i][n+d+1]=1;
                              f1=d=0;
                          }
                          continue;
                    }
                    d=d*10+c-'0';
                    f1=1;
               }
               if(f1) map[i][n+d+1]=1;
          }
          for(int i=1;i<=n;i++)
             map[s][i]=1;
          int high=1000,low=1,mid;
          while(low+1<high)
          {
               //printf("%d %d\n",low,high);
               mid=low+high>>1;
               if(ok(mid)) high=mid;
               else low=mid;
          }
          printf("%d\n",high);
          /*for(int i=0;i<=n+m;i++,puts(""))
              for(int j=0;j<=n+m;j++)
                  printf("%d ",map[i][j]);*/
    }
}
