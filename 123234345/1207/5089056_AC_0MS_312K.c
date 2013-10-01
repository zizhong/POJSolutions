#include<stdio.h>
main()
{
   int num1,num2;
   while(scanf("%d%d",&num1,&num2)!=EOF)
   {
      int a,b;
      if(num1>num2) a=num2,b=num1;
      else a=num1,b=num2;  
      int max=0,i,j;
      for(i=a;i<=b;i++)
      {
          int ni=1;
          j=i;
         while(j!=1)
          {
             ni++;
             if(j%2) j=3*j+1;
             else j/=2;
          }
          max=max<ni?ni:max;
      }
      printf("%d %d %d\n",num1,num2,max);
   }
}
