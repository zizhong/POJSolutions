#include<cstdio>
typedef __int64 LL;
LL ex_gcd(LL a,LL b,LL &x,LL &y)
{
    if(!b){x=1,y=0;return a;}
    LL ret=ex_gcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
const int N=1000000;
LL k,a[N],r[N];
LL ex_modular_system()
{
     LL lcm,d,ans;
     lcm=a[0],ans=a[0]+r[0];
     for(int i=1;i<k;i++)
     {
         LL x,y,b=r[i]-ans;
         d=ex_gcd(lcm,a[i],x,y);
         if(b%d) return -1;
         x*=(r[i]-ans)/d;
         ans+=((x%a[i]+a[i])%a[i])*lcm;
         lcm*=a[i]/d;
         ans=((ans%lcm)+lcm)%lcm;
     }
     return ans;
}
int main()
{
    while(scanf("%I64d",&k)==1)
    {
         for(int i=0;i<k;i++) scanf("%I64d%I64d",&a[i],&r[i]);
         printf("%I64d\n",ex_modular_system());
         
    }
}
