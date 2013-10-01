#include<cstdio>
#include<cstring>
#include<cmath>
struct Point
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
}p[100][40];
double f[40][40][100];
int s[100];
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
    
    for(int i=0;i<s[0];i++)
    {
        for(int j=1;j<n;j++)
            for(int k=0;k<s[j];k++)
            {
                 f[i][k][j]=f[i][0][j-1]+dis(p[j-1][0],p[j][k]);
                 for(int h=1;h<s[j-1];h++)
                 {
                     double tmp=f[i][h][j-1]+dis(p[j-1][h],p[j][k]);
                     if(tmp<f[i][k][j]) f[i][k][j]=tmp;
                 }
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
    ans*=100;int a=(int)ans;printf("%d\n",a);
    //scanf("%'d");
}
