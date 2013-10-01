#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=210;
double f[N][N],d[N][N];
struct Point 
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
       bool operator < (const Point &p1)const {return x<=p1.x;}
       double dis(Point &p1){return sqrt((x-p1.x)*(x-p1.x) + (y-p1.y)*(y-p1.y) );}
}p[N];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         for(int i=1;i<=n;i++)
              p[i].init();
         sort(p+1,p+1+n);
         for(int i=1;i<=n;i++)
             for(int j=1;j<i;j++)
               d[i][j]=d[j][i]=p[i].dis(p[j]);
         f[2][1]=d[2][1];
         for(int i=3;i<=n;i++)
         {
               for(int j=1;j<i-1;j++)
                  f[i][j]=f[i-1][j]+d[i-1][i];
               f[i][i-1]=1e10;
               for(int k=1;k<i-1;k++)
                   f[i][i-1]=min(f[i][i-1],f[i-1][k]+d[k][i]);
               //f[i][i]=f[i][i-1]+d[i][i-1];
         }
         printf("%.2f\n",f[n][n-1]+d[n-1][n]);
    }
}
