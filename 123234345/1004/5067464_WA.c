#include<stdio.h>
int main()
{
   int i;
   double sum=0,account[12];
   for(i=0;i<12;i++)
  {  
    scanf("%ld",&account[i]);
    sum+=account[i];
  }
  printf("$%.2lf\n",sum/12);
}
