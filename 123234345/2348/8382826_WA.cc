#include<stdio.h>
int SG(int a,int b)
{
    if(a==b) return 1;
    if(b>=2*a) return 1;
    return 1^SG(b-a,a);
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a)
    {
         if(a>b) {int t=a;a=b;b=t;}
         puts(SG(a,b)?"Stan wins":"Ollie wins");
    }
}
