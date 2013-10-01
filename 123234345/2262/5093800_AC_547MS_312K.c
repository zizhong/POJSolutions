#include<stdio.h>
int prime(int n)
{
    int i;
    if(n==2) return 1;
    for(i=2;i<=sqrt(n);i++)
       if(n%i==0) return 0;
    return 1;
}
main()
{
      int n,i;
      while(scanf("%d",&n)&&n)
      {
         for(i=2;i<n;i++)
           if(prime(i)&&prime(n-i))
             break;
         if(i==n) printf("Goldbach's conjecture is wrong.\n");
         else printf("%d = %d + %d\n",n,i,n-i);
      }
}
