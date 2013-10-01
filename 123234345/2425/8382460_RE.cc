#include<stdio.h>
#include<string.h>
const int N=1010,M=N*N/2;
int n;
int fir[N],next[M],vex[M],cnt;
int SG[N],vsg[N];
void init()
{
     memset(fir,-1,sizeof(fir));
     memset(vsg,0,sizeof(vsg));
     cnt=0;
}
void insert(int u,int v)
{
     vex[cnt]=v;
     next[cnt]=fir[u];
     fir[u]=cnt++;
}
int cal_SG(int x)
{
    if(vsg[x]) return SG[x];
    vsg[x]=1;
    int vv[N]={0};
    for(int v=fir[x];v!=-1;v=next[v])
    {
         vv[cal_SG(vex[v])]=1;
    }
    int sg=0;
    while(vv[sg]) sg++;
    SG[x]=sg;
    return sg;
}
int main()
{
    while(scanf("%d",&n),n)
    {
         init();
         for(int i=0;i<n;i++)
         {
             int m,v;
             scanf("%d",&m);
             while(m--)
             {
                  scanf("%d",&v);
                  insert(i,v);
             }
         }
         for(int i=0;i<n;i++) cal_SG(i);
         int nq;
         while(scanf("%d",&nq),nq)
         {
              int sg=0,v;
              for(int i=0;i<nq;i++)
              {
                   scanf("%d",&v);
                   sg^=SG[v];
              }
              puts(sg?"WIN":"LOSE");
         }
    }
}
