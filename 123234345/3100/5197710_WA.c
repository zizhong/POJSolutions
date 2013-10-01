#include<stdio.h>
int main()
{
    double b,n;
    while(scanf("%lf%lf",&b,&n)&&b)
    {
        double r=log(b)/log(n);
        long floor=r,ceil=floor+1;
        if(b-pow(floor,n)<pow(ceil,n)-b) printf("%ld\n",floor);
        else printf("%ld\n",ceil);
    }
    
}
