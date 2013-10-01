#include<stdio.h>
const int N=201;
double _min(double a,double b){return a<b?a:b;}
double _max(double a,double b){return a>b?a:b;}
double g[N][N],x[N],y[N],rt;
int n;
int main()
{
    while(scanf("%d",&n), n)
    {
        for(int i=1;i<=n;i++)
        {
             scanf("%lf%lf",&x[i],&y[i]);
             for(int j=1;j<i;j++)
                  g[i][j]=g[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);             
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
               for(int j=1;j<=n;j++)
                   g[i][j]=_min(g[i][j],_max(g[i][k],g[k][j]));
        printf("Scenario #%d\nFrog Distance = %.3f\n\n",++t,sqrt(g[1][2]));
    }
}
