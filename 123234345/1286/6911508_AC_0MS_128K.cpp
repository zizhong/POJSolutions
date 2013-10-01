#include<stdio.h>
int gcd(int a,int b){return b?gcd(b,a%b):a;}
__int64 ex(int n){__int64 r=1;while(n--) r*=3;return r;}
int main()
{
    int n;
    while(scanf("%d",&n),n+1)
    {
          if(n==0)
          {
                  printf("0\n");
                  continue;
          }
          __int64 ans=0;
          for(int i=0;i<n;i++)
              ans+=ex(gcd(n,i));
          if(n&1)
          {
                 ans+=ex(n/2+1)*n;
          }
          else
          {
                 ans+=ex(n/2)*n/2;
                 ans+=ex(n/2+1)*n/2;
          }
          printf("%I64d\n",ans/2/n);
    }
} 
