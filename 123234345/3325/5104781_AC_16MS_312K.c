#include<stdio.h>
main()
{
   int n;
   while(scanf("%d",&n)&&n)
   {
       int i,s,sum=0,max=0,min=1000;
       for(i=0;i<n;i++)
       {
           scanf("%d",&s);
           sum+=s;
           if(s>max) max=s;
           if(s<min) min=s;
       }
       printf("%d\n",(sum-max-min)/(n-2));
   }
}
