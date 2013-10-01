#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
     return b?gcd(b,a%b):a;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a&&b)
    {
          printf("%lld\n",(long long )a/gcd(a,b)*b/gcd(a,b));
    }
}