#include<stdio.h>
main()
{
   int i;
   double sum=0,account[12]={0};
   for(i=0;i<12;i++)
  {  
    scanf("%lf",&account[i]);
    sum+=account[i];
  }
  printf("$%.2lf\n",sum/12);
}
