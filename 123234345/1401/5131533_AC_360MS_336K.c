#include<stdio.h>
main()
{
      long a;
      int t;
      scanf("%d",&t);
      while(t--)
      {
          scanf("%ld",&a);
          int result=0;
          while(a)
          {
              a/=5;
              result+=a;
          }
          printf("%d\n",result);
      }
      
}
