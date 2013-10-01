#include<stdio.h>
#include<math.h>
const int N=101;
const double inf=999999999;
double p[N][2],g[N][N];
double d[N];
int a[N][2];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       scanf("%lf%lf",&p[i][0],&p[i][1]);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       if(i!=j) g[i][j]=sqrt((p[i][0]-p[j][0])*(p[i][0]-p[j][0])+(p[i][1]-p[j][1])*(p[i][1]-p[j][1]));
    double min;
    int tail;
    for(int i=1;i<=n;i++)
        d[i]=g[1][i],a[i][0]=1;
    a[1][1]=1;
    while(1)
    {
            min=inf;
            for(int i=2;i<=n;i++)
               if(a[i][1]==0&&d[i]<min)
               {
                    min=d[i];
                    tail=i;
               }
            if(fabs(min-inf)<1e-8) break;
            a[tail][1]=1;
            for(int i=1;i<=n;i++)
            {
                    if(a[i][1]==0&&g[tail][i]<d[i])
                    {
                        d[i]=g[tail][i];
                        a[i][0]=tail;
                    }
            }
    }
    double sum=0.0;
    for(int i=2;i<=n;i++)
       sum+=d[i];
    printf("%.2f\n",sum);
}
