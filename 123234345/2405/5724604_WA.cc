#include<stdio.h>
#include<math.h>
const double pi=3.14159;
int main()
{
    double D,V;
    while(scanf("%lf%lf",&D,&V),D||V)
         printf("%.3f\n",pow(D*D*D-6*V/pi,1.0/3));
}
