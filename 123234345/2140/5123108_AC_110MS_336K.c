#include<stdio.h>
main()
{
   int n,i,r=0;
   scanf("%d",&n);
   for(i=1;i<=n;i+=2)
     if(n%i==0) r++;
   printf("%d\n",r);
}
