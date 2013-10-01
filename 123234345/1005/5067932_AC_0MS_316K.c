#include<stdio.h>
#include<math.h>
#define PI 3.14159265
main()
{
   int i=0,t,h;
   scanf("%d",&t);
   h=t;
   while(t--)
   {
   double x,y;
   scanf("%lf%lf",&x,&y);
   for(i=1;100*i/PI<(x*x+y*y);i++);
   printf("Property %d: This property will begin eroding in year %d.\n",h-t,i);
   }
   printf("END OF OUTPUT.\n");
}
