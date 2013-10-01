#include<stdio.h>
#include<string.h>
const int N=104,INF=0x7ffffff;
int m,n;
int c[N][N];
int maxflow(int s,int t)
{
     int p,q,queue[N],u,v,pre[N];
     int flow,aug;
     flow=0;
     while(true)
     {
         memset(pre,-1,sizeof(pre));
         for(queue[p=q=0]=s;p<=q;p++)
         {
             u=queue[p];
             for(v=0;v<n&&pre[t]<0;v++)if(c[u][v]>0&&pre[v]<0)
                 pre[v]=u,queue[++q]=v;
             if(pre[t]>=0)break;
         }
         if(pre[t]<0)break;
         aug=INF;
         for(u=pre[v=t];v!=s;v=u,u=pre[u])if(c[u][v]<aug)aug=c[u][v];
         for(u=pre[v=t];v!=s;v=u,u=pre[u])c[u][v]-=aug,c[v][u]+=aug;
         flow+=aug;
     }
     return flow;
}
int main()
{
    int g;
    int p[1001]={0},v[1001]={0};
    memset(v,-1,sizeof(v));
    scanf("%d%d",&m,&g);
    n=g+2;
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    for(int gi=1;gi<=g;gi++)
    {
         int key,ki;
         scanf("%d",&key);
         for(int k=1;k<=key;k++)
         {
               scanf("%d",&ki);
               if(v[ki]==-1)
                    c[0][gi]+=p[ki];
               else 
                    c[v[ki]][gi]=INF;
               v[ki]=gi;
         }
         int t;
         scanf("%d",&t);
         c[gi][g+1]=t;
    }
    printf("%d\n",maxflow(0,g+1));}
