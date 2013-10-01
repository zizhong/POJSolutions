#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
int main()
{
    int n,h;
    scanf("%d",&n);
    h=n;
    while(n--)
    {
        double R,r;
        int m;
        scanf("%lf%d",&R,&m);
        r=(R*sin(PI/m))/(1+sin(PI/m));
        printf("Scenario #%d:\n%.3lf\n\n",h-n,r);
    }
}
