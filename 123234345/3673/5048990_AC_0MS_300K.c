#include<stdio.h>
main()
{
   char c;
   int a[2]={0};
   c=getchar();
   while(c>='0'&&c<='9')
   {  
       a[0]+=c-'0';
       c=getchar();      
   }
    c=getchar();
   while(c>='0'&&c<='9')
   {
       a[1]+=c-'0';
       c=getchar();
   }
   printf("%d\n",a[0]*a[1]);
}
