#include<stdio.h>
main()
{
   while(1)
   {
   int a[8]={0};
   int day=0,max=0,n,i,k,l;
   scanf("%d",&n);
   if(n==0) break;
   for(i=1;i<=n;i++)
   {
      scanf("%d%d",&k,&l);
      a[i]=k+l;
   }
   for(i=1;i<=n;i++)
     if(a[i]>8&&a[day]<a[i])
         day=i;
   printf("%d\n",day);
   }
}
