#include<stdio.h>
const int N=111;
__int64 gcd(__int64 a,__int64 b){return b?gcd(b,a%b):a;}
class Rational
{
      public : 
      __int64 a,b;
      Rational operator + (const Rational &r2)
      {
               Rational rt;
               __int64 d=gcd(a*r2.b+b*r2.a,b*r2.b);
               rt.a=(a*r2.b+b*r2.a)/d;
               rt.b=b*r2.b/d;
               return rt;
      }
      Rational operator - (const Rational &r2)
      {
               Rational rt2=r2;
               rt2.a*=-1;
               return (*this)+rt2; 
      }
      Rational operator * (const Rational &r2)
      {
               Rational rt;
               __int64 d=gcd(a*r2.a,b*r2.b);
               rt.a=a*r2.a/d;
               rt.b=b*r2.b/d;
               return rt;
      }
      Rational operator / (const Rational &r2)
      {
               Rational rt2=r2;
               __int64 tt=rt2.a;rt2.a=rt2.b;rt2.b=tt;
               return (*this)*rt2;
      }
      bool operator == (const Rational &r2)
      {
           return a==r2.a && b==r2.b;
      }
};
struct Point{Rational x,y;}p[111];
Point inter(Point &u1,Point &u2,Point &v1,Point &v2)
{
    Point ret=u1;
    Rational t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))
            /((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x=ret.x+(u2.x-u1.x)*t;
    ret.y=ret.y+(u2.y-u1.y)*t;
    return ret;
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
          scanf("%I64d%I64d",&p[i].x.a,&p[i].y.a);
          p[i].x.b=p[i].y.b=1;
    }
    scanf("%d",&m);
    int ans=-1;
    for(int i=1;i<=m;i++)
    {
           int a,b,c,d;
           scanf("%d%d%d%d",&a,&b,&c,&d);
           if(ans==-1)
           {
                 Point p0=inter(p[a],p[b],p[c],p[d]);
                 p[n+i]=p0;
                 if(p0.x.a==0&&p0.y.a==0)
                      ans=i;
           }
    }
    printf("%d\n",ans>-1?ans:0);
}
