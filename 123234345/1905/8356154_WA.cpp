#include<stdio.h>
#include<math.h>
const double eps=1e-8,pi=acos(-1.0);
double x,x1,d,c;
double cal(double C)
{
       double l=0,r=pi/2;
       while(r-l>eps)
       {
             double mid=(l+r)*0.5;
             double tmp=sin(mid)/mid;
             if(tmp<C) r=mid;
             else l=mid; 
       }
       return l;
}
int main()
{
    while(scanf("%lf%lf%lf",&x,&d,&c),x>-eps)
    {
         x1=(1+d*c)*x;
         double alpha=cal(x/x1);
         double ans=x1*(1-cos(alpha))/alpha*0.5;
         printf("%.3f\n",ans);
    }
}
