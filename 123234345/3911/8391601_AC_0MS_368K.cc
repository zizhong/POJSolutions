#include<stdio.h>
int main()
{
    int n,c;
    while(scanf("%d%d",&n,&c)==2)
    {
         if(n==0||c==0) {puts("0");continue;}
         int x=c/2/n;
         int t=x+1;
         if(n*t*(c-t*n)>n*x*(c-x*n)) x=t;
         else if(x>0&&n*x*(c-x*n)<=n*(x-1)*(c-(x-1)*n)) x--;
         printf("%d\n",x);
    }
}
