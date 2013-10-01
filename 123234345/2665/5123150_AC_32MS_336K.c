#include<stdio.h>
main()
{
   int l,s,i,a,b;
   while(scanf("%d%d",&l,&s))
   {
      if(l==0&&s==0) break;
      while(s--)
      {
        scanf("%d%d",&a,&b);
        l-=-a+b+1;
      }
      printf("%d\n",l+1);
   }
}
