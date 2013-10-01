#include<stdio.h>
#include<math.h>
#include<string.h>
const int N=201,MAX=99999999;
double _min(double a,double b){return a<b?a:b;}
double g[N][N],x[N],y[N],rt;
int vst[N],n;
void dfs(int i,double ans)
{
     for(int j=2;j<=n;j++)
     {
          if(!vst[j])
          {
               ans=_min(ans,g[i][j]);
               if(j==2)
               {
                    rt=_min(ans,rt);
                    continue;
               }
               vst[j]=1;
               dfs(j,ans);
               vst[j]=0;
          }
     }
}
int main()
{
    int t=0;
    while(scanf("%d",&n), n)
    {
        for(int i=1;i<=n;i++)
        {
             scanf("%lf%lf",&x[i],&y[i]);
             for(int j=1;j<i;j++)
                  g[i][j]=g[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);             
        }
        memset(vst,0,sizeof(vst));
        rt=MAX*1.0;
        dfs(1,rt);
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++t,sqrt(rt));
    }
}
