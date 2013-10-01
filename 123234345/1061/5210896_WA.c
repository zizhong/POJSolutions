#include<stdio.h>
void Extented_Euclid(int a,int b,int *d,int *x,int *y)
{
     int d1,x1,y1;
     if(b==0)
     {
         *d=a,*x=1,*y=0;
         return ;
     }
     Extented_Euclid(b,a%b,&d1,&x1,&y1); 
     *d=d1,*x=y1,*y=x1-(int)(a/b)*y1;    
}
void Modular_Linear_Equation_Solver(int a,int b,int n)
{
    int d,x1,y1,x0,i;
    Extented_Euclid(a,n,&d,&x1,&y1);
    if(b%d==0)
    {
        x0=x1*(b/d)%n;
        printf("%d\n",(x0+n)%n);
    }
    else
       printf("Impossible\n");
}
int main()
{
    int x,y,m,n,l;
    while(scanf("%d%d%d%d%d",&x,&y,&m,&n,&l)+1)
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
    }}
