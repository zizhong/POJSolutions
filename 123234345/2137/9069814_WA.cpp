#include<cstdio>
#include<cstring>
#include<cmath>
struct Point
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
}p[110][41];
double f[41][41][110];
int s[110];
double dis(Point &p1,Point &p2)
{
       return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d",&s[i]);
         for(int j=0;j<s[i];j++)
              p[i][j].init();
    }
    for(int i=0;i<s[0];i++) f[0][0][0]=0;
    for(int i=0;i<s[0];i++)
        for(int j=1;j<n;j++)
            for(int k=0;k<s[j];k++)
            {
                 f[i][k][j]=1e9;
                 for(int h=0;h<s[j-1];h++)
                 {
                     double tmp=f[i][h][j-1]+dis(p[j-1][h],p[j][k]);
                     if(tmp<f[i][k][j]) f[i][k][j]=tmp;
                 }
            }
    double ans=1e9;
    for(int i=0;i<s[0];i++)
        for(int j=0;j<s[n-1];j++)
        {
             double tmp=f[i][j][n-1]+dis(p[0][i],p[n-1][j]);
             if(tmp<ans) ans=tmp;
        }
    //printf("%.0f\n",ans*100);
    int a=100*ans+1e-8;printf("%d\n",a);
    scanf("%'d");
}
