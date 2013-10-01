#include<stdio.h>
int f(int n,int m,int c)
{
    if(c==0) return (f(n-1,m,1)+f(n,m-1,1))/2;
    return (n-6)/2*(m-6)/2+(n-7)/2*(n-7)/2;
}
int main()
{
    int n,m,c;
    while(scanf("%d%d%d",&n,&m,&c),n)
    {
        printf("%d\n",f(n,m,c));
    }
}
