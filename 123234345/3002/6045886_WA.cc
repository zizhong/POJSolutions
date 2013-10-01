#include<stdio.h>
int gcd(int a,int b)
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
              int ans=1;
              scanf("%d",&w);
              for(int i=0;i<w;i++)
              {
                      int a;
                      scanf("%d",&a);
                      ans=ans/gcd(a,ans)*a;
              }
              printf("%d\n",ans);
    }
}
