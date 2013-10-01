#include<stdio.h>
int mod(int n,int m)
{
    return n-n/m*m;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
         printf("%d\n",mod(a,b));
    }
}
