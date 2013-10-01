#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
int main()
{
     float  ax, ay, bx, by, cx, cy;
     while(scanf("%f%f%f%f%f%f",&ax,&ay,&bx,&by,&cx,&cy)!=EOF)
     {
          float a=sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)),
                 b=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)),
                 c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)),
                 t=(a+b+c)/2,
                 area=sqrt(t*(t-a)*(t-b)*(t-c)),
                 r=a*b*c/(4*area),
                 C=2*PI*r;
          printf("%.2f\n",C);
     }
}

