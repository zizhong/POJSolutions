#include<iostream>
#include<stdio.h>
using namespace std;
void Extented_Euclid(long long a,long long b,long long *d,long long *x,long long *y)
{
     long long d1,x1,y1;
     if(b==0)
     {
         *d=a,*x=1,*y=0;
         return ;
     }
     Extented_Euclid(b,(a%b+b)%b,&d1,&x1,&y1); 
     *d=d1,*x=y1,*y=x1-(a/b)*y1;    
}
void Modular_Linear_Equation_Solver(long long a,long long b,long long n)
{
    long long d,x1,y1,x0,i;
    Extented_Euclid(a,n,&d,&x1,&y1);
    if(b%d==0)
    {
        x0=x1%n*(b/d)%n;
        x0=(x0%(n/d)+n/d)%(n/d);
        cout<<x0<<endl;
    }
    else
       printf("FOREVER\n");
}
long long h[40];
int main()
{
    long long a,b,c,k;
    h[0]=1;
    for(int i=1;i<=32;i++)
        h[i]=2*h[i-1];
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k)&&(a||b||c||k))
     Modular_Linear_Equation_Solver(c,(b-a+h[k])%h[k],h[k]);
}


