#include<stdio.h>
float a[100000];
float find(int n)
{
    if(n==0) return a[0];
    if(a[n]) return a[n];
    a[n]=find(n-1)+1.0/(2*n);
    return a[n];
}
main()
{
   int n;
   printf("Cards  Overhang\n");
   while(scanf("%d",&n)!=EOF)
      printf("%5d     %.3f\n",n,find(n));
}
