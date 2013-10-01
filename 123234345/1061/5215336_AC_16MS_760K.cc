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
       printf("Impossible\n");
}
int main()
{
    long long x,y,m,n,l;
    while(cin>>x>>y>>m>>n>>l)
    {
    x%=l,y%=l;
    if(m==n)
    {
        printf("Impossible\n");
        continue;
    }
    if(m>n&&x>y) Modular_Linear_Equation_Solver(m-n,l-(x-y),l);
    if(m>n&&x<y) Modular_Linear_Equation_Solver(m-n,y-x,l);
    if(m<n&&x>y) Modular_Linear_Equation_Solver(n-m,x-y,l);
    if(m<n&&x<y) Modular_Linear_Equation_Solver(n-m,l-(y-x),l);
    }
}

