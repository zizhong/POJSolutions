#include<stdio.h>
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       if(a>=b) printf("MMM BRAINS\n");
       else printf("NO BRAINS\n");
    }
}