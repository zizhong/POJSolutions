#include <stdio.h>
#include <math.h>
#define ll long long 
int prime[1100];
 
ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}
 
ll Getphi(ll n){
    ll count = 0, i;
    ll ans = n;
    if(n % 2 == 0){
       prime[count++] = 2;
       while(n % 2 == 0) n /= 2;
    }
    for(i = 3; i <= (ll)sqrt((long double)n) + 1 && n >= i; i += 2)
       if(n % i == 0){
           prime[count ++] = i;
           while(n % i == 0) n /= i;
       }
    if(n > 1) prime[count++] = n;
    for(i = 0; i < count; i ++)
       ans = (ans / prime[i]) * (prime[i] - 1);
    return ans;
}
 
ll muilt(ll a, ll b, ll c){
    ll temp = 0;
    a %= c;
    while(b){
       if(b & 1) temp = (temp + a) % c;
       a = (a + a) % c;
       b >>= 1;
    }
    return temp;
}
 
ll Can_mod(ll a, ll b, ll c)
{
    ll temp = 1;
    a %= c;
    while(b)
    {
       if(b & 1) temp = muilt(temp , a, c);
       a = muilt(a, a, c);
       b >>= 1;
    }
    puts("--");
    return temp == 1;
}
 
int main(){
    ll l, t, n, PHI, i, SQRT, ans, DI;
    int CASE = 0;
    while(~scanf("%lld", &l), l){
       ans = 0;
       printf("Case %d: ", ++CASE);
       t = gcd(l, 8);
       DI = 9 * l / gcd(l, 8);
       if(gcd(10, DI) != 1) { printf("0\n"); continue; }
       PHI = Getphi(DI); ans = PHI; 
       SQRT = (ll)sqrt(1.0*PHI) + 1;
       for(i = 1; i <= SQRT; i ++)
           if(PHI % i == 0 && Can_mod(10, i, DI)){
              ans = i;
              break;
           }
       if(ans == PHI)
           for(i = SQRT; i >= 2; i --)
              if((PHI % i == 0) && Can_mod(10, PHI / i, DI)){
                  ans = PHI / i;
                  break;
              }
       printf("%lld\n",ans);
    }
    return 0;
}
 
