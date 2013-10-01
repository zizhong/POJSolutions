#include<stdio.h>
int main()
{
    double n;
    while(scanf("%lf",&n)==1)
    {
         while(n>18) n/=18;
         if(n>=1&&n<=9) puts("Stan wins.");
         else puts("Ollie wins.");
    }
}
