#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double D,d,s;
        scanf("%lf%lf%lf",&D,&d,&s);
        printf("%d\n",(int)(3.1415926/asin((s+d)/(D-d))));
    }
}
