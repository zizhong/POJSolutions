#include<stdio.h>
main()
{
   int i,j,k,t,n,max;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%d",&n);
       int a[401]={0};
       max=0;
       while(n--)
       {  
          
          scanf("%d%d",&i,&j);
          for(k=i;k<=j;k++) a[k]++;
          for(k=1;k<=400;k++)
            max=max<a[k]?a[k]:max;                    
       }
       printf("%d\n",max*10);
   }
}
