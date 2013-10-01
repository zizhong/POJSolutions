#include<stdio.h>
float a[300];
main()
{
   int i=0;
   float len=0;
   a[1]=1.0/2;
   for(i=1;a[i]<=5.20;i++)
     a[i+1]=a[i]+1.0/(i+2);
   while(scanf("%f",&len)&&len)
   {
      for(i=1;a[i]<len;i++);
      printf("%d card(s)\n",i);
   }
}
