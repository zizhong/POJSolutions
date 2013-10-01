#include<stdio.h>
#include<string.h>
const int N=1010;
int n,g[N][N];
int SG[N],vsg[N];
void init()
{
     memset(g,0,sizeof(g));
     memset(vsg,0,sizeof(vsg));
}
int cal_SG(int x)
{
    if(vsg[x]) return SG[x];
    vsg[x]=1;
    int vv[N]={0};
    for(int i=0;i<n-1;i++)
    {
        if(g[x][i])
        {
             vv[cal_SG(i)]=1;
        }
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
                  g[i][v]=1;
             }
         }
         int nq;
         while(scanf("%d",&nq),nq)
         {
              int sg=0,v;
              for(int i=0;i<nq;i++)
              {
                   scanf("%d",&v);
                   sg^=cal_SG(v);
              }
              puts(sg?"WIN":"LOSE");
         }
    }
}
