#include<stdio.h>
#include<string.h>
const int N=103,INF=0xffffff;
int n;
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
              for(v=0;v<n&&pre[t]<0;v++) if(c[u][v]>0&&pre[v]<0)
                   pre[v]=u,queue[++q]=v;
              if(pre[t]>=0) break;
         }
         if(pre[t]<0) break;
         aug=INF;
         for(u=pre[v=t];v!=s;v=u,u=pre[u]) if(aug>c[u][v]) aug=c[u][v];
         for(u=pre[v=t];v!=s;v=u,u=pre[u]) c[u][v]-=aug,c[v][u]+=aug;
         flow+=aug;
    }
    return flow;
}
int main()
{
    int m,np,nc;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
         memset(c,0,sizeof(c));
         for(int i=0;i<m;i++)
         {
              char s[50];
              scanf("%s",s);
              int u=0,v=0,w=0;
              int j=1;
              while(s[j]>='0'&&s[j]<='9') u=u*10+(s[j]-'0'),j++;
              j++;
              while(s[j]>='0'&&s[j]<='9') v=v*10+(s[j]-'0'),j++;
              j++;
              while(s[j]>='0'&&s[j]<='9') w=w*10+(s[j]-'0'),j++;
              j++;
              c[u][v]+=w;
         }
         for(int i=0;i<np;i++)
         {
              char s[50];
              int p=0,z=0;
              scanf("%s",s);
              int j=1;
              while(s[j]>='0'&&s[j]<='9') p=p*10+(s[j]-'0'),j++;
              j++;
              while(s[j]>='0'&&s[j]<='9') z=z*10+(s[j]-'0'),j++;
              j++;
              c[n][p]=z;
         }
         for(int i=0;i<nc;i++)
         {
              char s[50];
              int p=0,z=0;
              scanf("%s",s);
              int j=1;
              while(s[j]>='0'&&s[j]<='9') p=p*10+(s[j]-'0'),j++;
              j++;
              while(s[j]>='0'&&s[j]<='9') z=z*10+(s[j]-'0'),j++;
              j++;
              c[p][n+1]=z;
         }
         n+=2;
         /*for(int i=0;i<n;i++,puts(""))
            for(int j=0;j<n;j++)
            {
                  printf("%3d",c[i][j]);
            }*/
         printf("%d\n",maxflow(n-2,n-1));
    }    
}
