#include<string.h>
#include<stdio.h>
const int N=1001;
int m,n;
int c[N][N];
void maxflow(int s,int t)
{
     int p,q,queue[N],u,v,pre[N*10];
     int flow,aug;
     flow=0;
     //while(true)
     {
         memset(pre,-1,sizeof(pre));
         for(queue[p=q=0]=s;p<=q;p++)
         {
             u=queue[p];
             for(v=0;v<n&&pre[t]<0;v++)if(c[u][v]>0&&pre[v]<0)
                 pre[v]=u,queue[++q]=v;
             if(pre[t]>=0)break;
         }
         //if(pre[t]<0)break;
         aug=0x7fffffff;
         for(u=pre[v=t];v!=s;v=u,u=pre[u])if(c[u][v]<aug)aug=c[u][v];
         for(u=pre[v=t];v!=s;v=u,u=pre[u])c[u][v]-=aug,c[v][u]+=aug;
         if(flow<aug) flow=aug;
         printf("%d\n",aug);
     }
     //printf("%d\n",flow);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
          memset(c,0,sizeof(c));
          scanf("%d%d",&n,&m);
          for(int i=1;i<=m;i++)
          {
               int si,ei,ci;
               scanf("%d%d%d",&si,&ei,&ci);
               c[si-1][ei-1]=ci>c[si-1][ei-1]?ci:c[si-1][ei-1];
               c[ei-1][si-1]=c[si-1][ei-1];
               
          }
          printf("Scenario #%d:\n",tt);
          maxflow(0,n-1);
    }
}

