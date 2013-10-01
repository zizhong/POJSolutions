#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   double a,b;
   while(scanf("%lf%lf",&a,&b),a!=0&&b!=0) 
   {
      int i,j;
      for(i=0;i<1000000;i++)
            if(pow(i,b)>=a)break;
      if(pow(i,b)-a>=a-pow(i-1,b))
      printf("%d\n",i-1);
      else printf("%d\n",i);                                          
   } 
  return 0;
}

