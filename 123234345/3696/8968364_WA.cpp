#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef unsigned __int64 LL;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
/*LL phi(LL n)
{
   LL ret=1,i;
   LL sqrtN=(LL)sqrt(n*1.0)+1;
   for(i=2;i<=sqrtN;i++) if((n/i)*i==n)
   {
        n/=i;
        ret*=i-1;
        while(n%i==0) n/=i,ret*=i;
   }
   if(n>1) ret*=n-1;
   return ret;
}*/
LL prime[1100];
LL phi(LL n){
    LL count = 0, i;
    LL ans = n;
    if(n % 2 == 0){
       prime[count++] = 2;
       while(n % 2 == 0) n /= 2;
    }
    for(i = 3; i <= (LL)sqrt((long double)n) + 1 && n >= i; i += 2)
       if(n % i == 0){
           prime[count ++] = i;
           while(n % i == 0) n /= i;
       }
    if(n > 1) prime[count++] = n;
    for(i = 0; i < count; i ++)
       ans = (ans / prime[i]) * (prime[i] - 1);
    return ans;
}
/*LL mulmod(LL x,LL y,LL mod)
{
   LL ret=0;
   while(y)
   {
        if(y&1) ret=(ret+x)%mod;
        y>>=1;
        x=(x+x)%mod;
   }
   return ret;
}
LL powmod(LL x,LL y,LL mod)
{    
     LL ret=1;
     while(y)
     {
          if(y&1) ret=ret*x%mod;
          y>>=1;
          x=x*x%mod;
     }
     return ret;
}*/
LL muilt(LL a, LL b, LL c){
    LL temp = 0;
    a %= c;
    while(b){
       if(b & 1) temp = (temp + a) % c;
       a = (a + a) % c;
       b >>= 1;
    }
    return temp;
}
 
LL powmod(LL a, LL b, LL c){
    LL temp = 1;
    a %= c;
    while(b){
       if(b & 1) temp = muilt(temp , a, c);
       a = muilt(a, a, c);
       b >>= 1;
    }
    return temp == 1;
}
bool ok(LL x,LL a)
{
     LL ret=powmod(10,x,a);
     return (ret%a+a)%a == 1;
}
int main()
{
    LL a;
    int T=0;
    while(scanf("%I64d",&a),a)
    {
        a=9*a/gcd(a,8);
        LL ans;
        if(gcd(10,a)!=1) ans=0;
        else
        {
             LL PHI=phi(a),sqrtPHI=(LL)sqrt(PHI*1.0)+1;
             int flag=1;
             for(LL i=1;i<=sqrtPHI;i++) if(PHI%i==0 && ok(i,a))
             {
                  ans=i;
                  flag=0;
                  break;
             }
             for(int i=sqrtPHI;flag&&i>=2;i--) if(PHI%i==0 &&ok(PHI/i,a))
             {
                  ans=i;
                  break;
             }
        }
        printf("Case %d: ",++T);
        cout<<ans<<endl;
    }
}
