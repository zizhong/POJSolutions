#include<stdio.h>
#include<math.h>
double min(double a,double b)
{
       return a>b?b:a;
}
int main()
{
    double r,h,d1,a1,d2,a2,x,d;
    double pi=2*asin(1);
    while(scanf("%lf%lf%lf%lf%lf%lf",&r,&h,&d1,&a1,&d2,&a2)!=EOF)
    {
         x=r*fabs(a1-a2)/sqrt(r*r+h*h)*pi/180;
         x=min(x,2*pi*r/sqrt(r*r+h*h)-x);
         d=sqrt(d1*d1+d2*d2-2*d1*d2*cos(x));
         printf("%.2f\n",d);
    }
}
