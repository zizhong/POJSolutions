#include<stdio.h>
int main()
{
    double b,n;
    while(scanf("%lf%lf",&b,&n)&&b)
    {
        double r=pow(10,log10(b)/n);
        long floor=r,ceil=floor+1;
        if(b-pow(floor,n)<pow(ceil,n)-b) printf("%ld\n",floor);
        else printf("%ld\n",ceil);
    }
    
}
