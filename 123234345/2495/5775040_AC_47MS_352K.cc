#include<stdio.h>
int main()
{
    int nt;
    scanf("%d",&nt);
    for(int t=1;t<=nt;t++)
    {
         int a,b,c,d;
         scanf("%d%d%d%d",&a,&b,&c,&d);
         printf("Scenario #%d:\n%d\n\n",t,(a+b+c+d)%2);
    }
}
