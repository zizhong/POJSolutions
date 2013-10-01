#include<stdio.h>
main()
{
   int f1,f2,f0,a,b,c,f3,f4,f5;
   while(scanf("%d%d%d",&f0,&f1,&f2)!=EOF)
   {
       c=f0;
       a=(f2-f0)/2-f1+f0;
       b=f1-f0-a;
       printf("%d %d %d\n",9*a+3*b+c,16*a+4*b+c,25*a+5*b+c);
   }
}
