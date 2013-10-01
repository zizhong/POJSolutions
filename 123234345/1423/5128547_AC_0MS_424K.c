#include<stdio.h>
double arr[10001];
#define e 2.7182818284590452354
#define pi 3.141592653589793239
double Stiring(int a)
{
    return log10(sqrt(2*pi*a))+a*log10(a/e);
}
main()
{
      int i,n,t;
      for(i=1;i<=10000;i++)
          arr[i]=arr[i-1]+log10(i);
      scanf("%d",&t);
      while(t--)
      {
         scanf("%d",&n);
         if(n<=10000) printf("%d\n",(int)arr[n]+1);
         else {
         int result=(int)Stiring(n);
         if(result<=(int)Stiring(n)) result++;
         printf("%d\n",result);
         }
      }
}
