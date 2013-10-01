#include<stdio.h>
int SG(long long a,long long b)
{
    
    if(a==b) return 1;
    if(b>=2*a) return 1;
    return 1^SG(b-a,a);
}
int main()
{
    long long a,b;
    while(scanf("%lld%lld",&a,&b)==2&&(a+b))
    {
         if(a>b) {int t=a;a=b;b=t;}
         puts(SG(a,b)?"Stan wins":"Ollie wins");
    }
}
