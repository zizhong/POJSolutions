#include<stdio.h>
#include<math.h>
const double pi=acos(-1.0);
const double eps=1e-8;
double w,h;
int main()
{
    while(scanf("%lf%lf",&w,&h),w+h>eps)
    {
        double r1=h/2/(pi+1);
        double r2=w/pi/2;
        if(2*r1>w)
             r1=w/2;
        double v1=r1*r1*pi*w;
        double v2=r2*r2*(h-2*r2)*pi;
        printf("%.3f\n",v1>v2?v1:v2);
                 
    }
}
