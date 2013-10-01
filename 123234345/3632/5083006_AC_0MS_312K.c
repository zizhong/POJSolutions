#include<stdio.h>
main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       int max=0,min=99,m,num;
       scanf("%d",&m);
       while(m--)
       {
          scanf("%d",&num);
          max=max<num?num:max;
          min=min>num?num:min;
       }
       printf("%d\n",2*(max-min));
   }
}
