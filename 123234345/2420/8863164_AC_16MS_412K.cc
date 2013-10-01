#include<stdio.h>
#include<cmath>
const int N=110;
const double inf=1234567898765321.0,eps=1e-6;
struct Point
{
     double x,y;      
}p[N];
int n;
double Dist(double x,double y)
{
       double ans=0;
       for(int i=0;i<n;i++)
          ans+=sqrt((p[i].x-x)*(p[i].x-x)+(p[i].y-y)*(p[i].y-y));
       return ans;
}
double func(double tx,double l,double r)
{
       while(r-l>=eps)
       {
            double m1=(2*l+r)/3;
            double m2=(l+r*2)/3;
            if(Dist(tx,m1)<Dist(tx,m2)) r=m2;
            else l=m1; 
       }
       return Dist(tx,l);
}
int main()
{
    while(scanf("%d",&n)==1)
    {
         double lx=inf,rx=-inf,ly=inf,ry=-inf;
         for(int i=0;i<n;i++)
         {
              scanf("%lf%lf",&p[i].x,&p[i].y);
              if(p[i].x<lx) lx=p[i].x;
              if(p[i].x>rx) rx=p[i].x;
              if(p[i].y<ly) ly=p[i].y;
              if(p[i].y>ry) ry=p[i].y;
         }
         while(rx-lx>=eps)
         {
              double mx1=(rx+2*lx)/3;
              double mx2=(rx*2+lx)/3;
              if(func(mx1,ly,ry)<func(mx2,ly,ry)) rx=mx2;
              else lx=mx1;
         }
         printf("%.0f\n",func(lx,ly,ry));
    }
}
