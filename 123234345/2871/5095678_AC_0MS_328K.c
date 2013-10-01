#include<stdio.h>
main()
{
   float a,b;
   scanf("%f",&a);
   while(scanf("%f",&b)&&b!=999)
   {
      printf("%.2f\n",b-a);
      a=b;
   }
  printf("End of Output\n"); 
}