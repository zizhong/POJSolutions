#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8,pi=acos(-1.0);
int sgn(double x){return (x>eps) - (x<-eps);}
struct Point
{
    double x,y;
    Point (double xx=0,double yy=0): x(xx),y(yy){};
}p[10010];
bool cmp(const Point &p1,const Point &p2)
{
    return p1.x==p2.x?p1.y>p2.y:p1.x<p2.x;
}
int n;
void calc(double alpha,double &h,double &r)
{
    h=0,r=0;
    for(int i=0;i<n;i++)
    {
        double x=p[i].x,y=p[i].y;
        double tmpr=x+y/tan(alpha),tmph=y+x*tan(alpha);
        if(h+eps<tmph) h=tmph,r=tmpr;
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
        {
            double x,y,z;
            scanf("%lf%lf%lf",&x,&y,&z);
            p[i]=Point(sqrt(x*x+y*y),z);
        }
        sort(p,p+n,cmp);
        
        int nn=1;
        for(int i=1;i<n;i++)
            if(sgn(p[nn-1].x-p[i].x)!=0)
                   p[nn++]=p[i];
        n=nn;
        
        double l=0+eps,r=pi/2-eps;
        while(l+eps<r)
        {
            double m1 = (l*2+r)/3,
                   m2 = (l+2*r)/3;
            double h1,r1,h2,r2;
            calc(m1,h1,r1);
            calc(m2,h2,r2);
             if(h1*r1*r1<h2*r2*r2)
                 r=m2;
            else l=m1;
        }
        double h1,r1;
        calc(l,h1,r1);
        printf("%.3f %.3f\n",h1,r1);
    }
}
