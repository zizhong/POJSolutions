#include <iostream>
using namespace std;

long long gcd(long long a,long long b,long long &x,long long &y)
{
long long d,t;
if(b==0)
{
   x=1;
   y=0;
   return a;
}
d=gcd(b,((a)%(b)+b)%b,x,y);
t=x;
x=y;
y=t-(a/b)*y;
return d;
}
int main()
{
long long x,y,m,n,l;
cin>>x>>y>>m>>n>>l;
long long d,t,p;
d=gcd(n-m,l,t,p);
if((x-y)%d||m==n)
   cout<<"Impossible"<<endl;
else
{
   long long s=l/d;
   t=t*(x-y)/d;    
   t=(t%s+s)%s;       cout<<t<<endl;
}
return 0;
}
