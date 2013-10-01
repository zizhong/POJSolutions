#include<stdio.h>
main()
{
    int t,h;
    scanf("%d",&t);
    h=t;
    while(t--)
    {
        int num;
        int q=0,d=0,n=0,p=0;
        scanf("%d",&num);
        q=num/25;
        num%=25;
        if(num>0)
        {
           d=num/10;
           num%=10;
           if(num>0)
           {
               n=num/5;
               num%=5;
               if(num>0)
                  p=num;           
           }
        }
       printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",h-t,q,d,n,p);
    }
}
