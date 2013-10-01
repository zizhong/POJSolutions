#include<stdio.h>
int a,b,c;
int val(int k,int base)
{
   int i,v=0,h=1,b=1;
   for(i=0;i<7;i++)
   {
       v+=(k/h%10)*b;
       h*=10;
       b*=base;
   }
   return v;
}
int findmaxd(int m)
{
   int maxd=0,i,d;
   int h=1;
   for(i=0;i<7;i++)
   {
       d=m/h%10;
       h*=10;
       if(d>maxd) maxd=d;
   }
   return maxd;
}
main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
   int dig,maxdig=0,i,r=0;
   scanf("%d%d%d",&a,&b,&c);
   dig=findmaxd(a);
   if(maxdig<dig) maxdig=dig;
   dig=findmaxd(b);
   if(maxdig<dig) maxdig=dig;
   dig=findmaxd(c);
   if(maxdig<dig) maxdig=dig;
   for(i=maxdig+1;i<=16;i++)
      if(val(a,i)*val(b,i)==val(c,i)) break;
   if(i<=16) r=i;
   printf("%d\n",r);
   }
}
