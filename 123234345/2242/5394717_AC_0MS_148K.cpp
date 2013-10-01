#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
int main()
{
     double  ax, ay, bx, by, cx, cy;
     while(scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy)!=EOF)
     {
          double a=sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)),
                 b=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)),
                 c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)),
                 t=(a+b+c)/2,
                 area=sqrt(t*(t-a)*(t-b)*(t-c)),
                 r=a*b*c/(4*area),
                 C=2*PI*r;
          printf("%.2lf\n",C);
     }
}
