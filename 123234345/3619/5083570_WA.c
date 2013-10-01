#include<stdio.h>
main()
{
   int n,k;
   scanf("%d%d",&n,&k);
   while(k--)
   {
      int s,t,r,rest,read;
      scanf("%d%d%d",&s,&t,&r);
      rest=n/(s*t)*r;
      read=n/s;
      if(!n%s) read++;
      printf("%d\n",read+rest);
   }
}