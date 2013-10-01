#include<stdio.h>
const int N=101;
struct point
{
       double x,y;
}p[N];
point gravity(point *p, int n)
{
 double area = 0;
 point center;
 center.x = 0;
 center.y = 0;

 for (int i = 0; i < n-1; i++)
 {
  area += (p[i].x*p[i+1].y - p[i+1].x*p[i].y)/2;
  center.x += (p[i].x*p[i+1].y - p[i+1].x*p[i].y) * (p[i].x + p[i+1].x);
  center.y += (p[i].x*p[i+1].y - p[i+1].x*p[i].y) * (p[i].y + p[i+1].y);
 }

 area += (p[n-1].x*p[0].y - p[0].x*p[n-1].y)/2;
 center.x += (p[n-1].x*p[0].y - p[0].x*p[n-1].y) * (p[n-1].x + p[0].x);
 center.y += (p[n-1].x*p[0].y - p[0].x*p[n-1].y) * (p[n-1].y + p[0].y);

 center.x /= 6*area;
 center.y /= 6*area;

 return center;
}
int main()
{
    int n,T=0;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%lf%lf",&p[i].x,&p[i].y);
         point res=gravity(p,n);
         printf("Stage #%d: %f %f\n",++T,res.x,res.y);
    }
}
