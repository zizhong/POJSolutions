#include<stdio.h>
int main()
{
    int a,b,t;
    scanf("%d",&t);
    while(t--)
    {
       int r;
       scanf("%d:%d",&a,&b);
       r=((a>=13)?a-12:12+a);
       if(b) r=0;
       printf("%d\n",r);
    }
}
