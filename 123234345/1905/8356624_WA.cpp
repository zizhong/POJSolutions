#include<stdio.h>
#include<math.h>
const double eps=1e-10,pi=acos(-1.0);
double x,x1,d,c;
double cal()
{
       double l=0,r=2.5;
       while(r-l>eps)
       {
             double mid=(l+r)*0.5;
             if(x1*sin(mid)<=x*mid) r=mid;
             else l=mid; 
       }
       return l;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("zzz.txt","w",stdout);
    while(scanf("%lf%lf%lf",&x,&d,&c),x>-eps)
    {
         x1=(1+d*c)*x;
         //if(x1-x>0.5*x) {printf("***\n");continue;}
         double alpha=cal();
         double ans=x1*(1-cos(alpha))/alpha*0.5;
         printf("%.3lf\n",ans);
    }
}
