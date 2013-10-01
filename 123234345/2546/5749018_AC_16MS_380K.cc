#include<stdio.h>
#include<math.h>
double pi=2*asin(1);
int main()
{
    double x1,y1,r1,x2,y2,r2,d,s,A,B,area;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
    if(r1<r2) d=r1,r1=r2,r2=d;
    d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(d>=r1+r2) area=0;
    else if(d<=r1-r2) area=pi*r2*r2;
    else
    {
        A=acos((d*d+r2*r2-r1*r1)/2/r2/d);
        B=acos((r1*r1+d*d-r2*r2)/2/r1/d);
        s=(r1+r2+d)/2;
        s=sqrt(s*(s-r1)*(s-r2)*(s-d));
        area=r1*r1*B+r2*r2*A-2*s;
    }
    printf("%.3f\n",area);
}
