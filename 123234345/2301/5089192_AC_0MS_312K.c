#include<stdio.h>
int main()
{
    int a,b,x,y;
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&a,&b);
       if(a%2!=b%2) printf("impossible\n");
       else
       {
           x=(a+b)/2;
           y=(a-b)/2;
           if(x>=y&&y>=0) printf("%d %d\n",x,y);
           else printf("impossible\n");
       }
    }
}
