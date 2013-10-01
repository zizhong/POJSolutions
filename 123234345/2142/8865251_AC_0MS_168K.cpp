#include<stdio.h>
int abs(int a){return a<0?-a:a;}
void ex_gcd(int a,int b,int& x0,int& y0,int& d)
{
    if(b==0)
    {
         d=a,x0=1,y0=0;
         return ;
    }
    int x1,y1;
    ex_gcd(b,a%b,x1,y1,d);
    x0=y1;
    y0=x1-a/b*y1;
}
int a,b,k;
int d,x0,y0;
bool better(int t1,int t)
{
     int x1=abs(b/d*t1+x0),y1=abs(y0-a/d*t1);
     int x=abs(b/d*t+x0),y=abs(y0-a/d*t);
     if(x1+y1<x+y) return true;
     if(x1+y1>x+y) return false;
     if(a*x1+b*y1<a*x+b*y) return true;
     return false;
}
int main()
{
    
    while(scanf("%d%d%d",&a,&b,&k),a+b+k)
    {
         ex_gcd(a,b,x0,y0,d);
         x0=x0*k/d,y0=y0*k/d;
         int ans=0;
         int t=(int)(-x0/(b/d));
         if(better(t,ans)) ans=t;
         if(better(t+1,ans)) ans=t+1;
         if(better(t-1,ans)) ans=t-1;
         t=(int)(y0/(a/d));
         if(better(t,ans)) ans=t;
         if(better(t+1,ans)) ans=t+1;
         if(better(t-1,ans)) ans=t-1;
         printf("%d %d\n",abs(b/d*ans+x0),abs(y0-a/d*ans));
    }
}
