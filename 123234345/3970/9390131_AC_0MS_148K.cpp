#include<cstdio>
#include<cstring>
__int64 num[20];
__int64 gcd(__int64 a,__int64 b){return b?gcd(b,a%b):a;}
__int64 lcm(__int64 a,__int64 b)
{
        __int64 d=gcd(a,b);
        return a/d*b;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             scanf("%I64d",&num[i]);
         __int64 dd=num[0];
         for(int i=1;i<n && dd<1000000;i++)
         {
              dd=lcm(dd,num[i]);
         }
         if(dd<1000000) printf("The CEO must bring %I64d pounds.\n",dd);
         else puts("Too much money to pay!");
    }
}
