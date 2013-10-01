#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
const int N=128;
struct Cell
{
       double x,y,z,r;
       void init(){scanf("%lf%lf%lf%lf",&x,&y,&z,&r);}
}cell[N];
double dist[N][N];
int n;
double calc_dist(Cell &c1,Cell &c2)
{
     return max(sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y)+(c1.z-c2.z)*(c1.z-c2.z))-c1.r-c2.r,0.0);
}
void solve()
{
     for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            dist[i][j]=dist[j][i]=calc_dist(cell[i],cell[j]);
     double d[N],inf=1e10;
     int vst[N];
     for(int i=0;i<n;i++) d[i]=dist[0][i],vst[i]=0;
     vst[0]=1;
     while(true)
     {
          double min=inf;
          int tail=-1;
          for(int i=0;i<n;i++)
              if(!vst[i] && min>d[i])
                  min=d[i],tail=i;
          if(tail==-1) break;
          vst[tail]=1;
          for(int i=0;i<n;i++)
             if(!vst[i] && d[i]>dist[tail][i])
                  d[i]=dist[tail][i];
     }
     double ans=0;
     for(int i=0;i<n;i++)
           ans+=d[i];
     printf("%.3f\n",ans);
}
int main()
{
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++) cell[i].init();
         solve();
    }
}
