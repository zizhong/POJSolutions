#include<stdio.h>
__int64 gcd(__int64 a,__int64 b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
              int w;
              __int64 ans=1;
              scanf("%d",&w);
              for(int i=0;i<w;i++)
              {
                      __int64 a;
                      scanf("%I64d",&a);
                      ans=ans/gcd(a,ans)*a;
              }
              printf("%I64d\n",ans);
    }
}
