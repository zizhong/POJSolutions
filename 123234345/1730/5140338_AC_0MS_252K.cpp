#include<stdio.h>
#include<math.h>
int main()
{
      double n;
      while(scanf("%lf",&n)&&n)
      {
         double p,b;
         long floor,ceil;
         if(n>0)
         {
             for(p=32;p>=1;p--)
             {
                b=pow(n,1/p);
                floor=b;
                ceil=b+1;
                if(b-floor<1e-12||ceil-b<1e-12)
                   {
                   printf("%.0lf\n",p);
                   break;
                   }
             }
         }
         else
         {
             n=-n;
             for(p=31;p>=1;p-=2)
             {
                b=pow(n,1/p);
                floor=b;
                ceil=b+1;
                if(b-floor<1e-12||ceil-b<1e-12)
                   {
                   printf("%.0lf\n",p);
                   break;
                   }
             }
         }
      }
      return 0;
}
