#include<stdio.h>
#include<cmath>
double _min(double a,double b){return a>b?b:a;}
struct Point
{
       double x,y;
};
int dblcmp(double d)
{
    if(fabs(d)<1e-8) return 0;
    return d>0?1:-1;
}
double det(double x1,double y1,double x2,double y2)
{
       return x1*y2-x2*y1;
}
double cross(Point a,Point b,Point c)
{
       return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int Segcross(Point a,Point b,Point c,Point d)
{
    return (dblcmp(cross(a,c,d))^dblcmp(cross(b,c,d)))==-2 &&
           (dblcmp(cross(c,a,b))^dblcmp(cross(d,a,b)))==-2;
}
double Seglen(Point a,Point b)
{
       return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    Point f1,f2,f3,f4;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&f1.x,&f1.y,&f2.x,&f2.y,&f3.x,&f3.y,&f4.x,&f4.y),f1.x>=0)   
    {
           double ans=1<<30;
           if(Segcross(f1,f2,f3,f4))
           {
                 ans=_min(ans,Seglen(f1,f2)+Seglen(f3,f4));
           }
           if(Segcross(f1,f3,f2,f4))
           {
                 ans=_min(ans,Seglen(f1,f3)+Seglen(f2,f4));
           }
           if(Segcross(f1,f4,f2,f3))
           {
                 ans=_min(ans,Seglen(f1,f4)+Seglen(f2,f3));
           }
           ans=_min(ans,Seglen(f1,f2)+Seglen(f1,f3)+Seglen(f1,f4));
           ans=_min(ans,Seglen(f2,f1)+Seglen(f2,f3)+Seglen(f2,f4));
           ans=_min(ans,Seglen(f3,f1)+Seglen(f3,f2)+Seglen(f3,f4));
           ans=_min(ans,Seglen(f4,f1)+Seglen(f4,f2)+Seglen(f3,f4));
           printf("%.4f\n",ans);
    }
}
