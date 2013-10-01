#include<stdio.h>
#define e 2.7182818284590452354
#define pi 3.141592653589793239
double Stiring(int a)
{
    return log10(sqrt(2*pi*a))+a*log10(a/e);
}
main()
{
      int i,n,t;
      scanf("%d",&t);
      int result;
      while(t--)
      {  
         scanf("%d",&n);
         result=(int)Stiring(n);         
         if(result<=(int)Stiring(n)) result++;
         printf("%d\n",result);
      }
}
