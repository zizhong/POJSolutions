#include<string.h>
#include<stdio.h>
int m,n;
int c[128][128];
int maxflow(int s,int t)
{
     int p,q,queue[128],u,v,pre[128];
     int flow,aug;
     flow=0;
     while(true)
     {
         memset(pre,-1,sizeof(pre));
         for(queue[p=q=0]=s;p<=q;p++)
         {
             u=queue[p];
             for(v=1;v<=n&&pre[t]<0;v++)if(c[u][v]>0&&pre[v]<0)
                 pre[v]=u,queue[++q]=v;
             if(pre[t]>=0)break;
         }
         if(pre[t]<0)break;
         aug=0x7fffffff;
         for(u=pre[v=t];v!=s;v=u,u=pre[u])if(c[u][v]<aug)aug=c[u][v];
         for(u=pre[v=t];v!=s;v=u,u=pre[u])c[u][v]-=aug,c[v][u]+=aug;
         flow+=aug;
     }
     return flow;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
          memset(c,0,sizeof(c));
          for(int i=1;i<=m;i++)
          {
               int si,ei,ci;
               scanf("%d%d%d",&si,&ei,&ci);
               c[si][ei]+=ci;
          }
          printf("%d\n",maxflow(1,n));
    }
}
