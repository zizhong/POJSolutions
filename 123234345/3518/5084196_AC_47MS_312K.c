#include<stdio.h>
int prime(int n)
{
    int i;
    for(i=2;i<=sqrt(n);i++)
       if(n%i==0) return 0;
    return 1;
}
main()
{
   int i,j,n;
   while(scanf("%d",&n)&&n)
   {
       for(i=n;!prime(i);i++);
       for(j=n;!prime(j);j--);
       printf("%d\n",i-j);
   }
}
