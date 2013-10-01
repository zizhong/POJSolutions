#include<stdio.h>
#define PI 3.1415927
int main()
{
    int nTrip=0;
    double d,t;
    int n;
    while(scanf("%lf%d%lf",&d,&n,&t)&&n)
    {
        double s,arv;
        ++nTrip;
        printf("Trip #%d:",nTrip);
        
        s=d*n*PI/5280/12;
        arv=s/(t/3600);
        
        printf(" %.2lf %.2lf\n",s,arv);
    }
}
