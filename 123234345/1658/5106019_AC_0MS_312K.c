#include<stdio.h>
int a[6];
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);
         if((a[2]-a[1]==a[3]-a[2])&&(a[4]-a[3]==a[3]-a[2]))
         printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[4]+a[2]-a[1]);
         else
         printf("%d %d %d %d %d\n",a[1],a[2],a[3],a[4],a[4]*(a[2]/a[1]));
    }
}
