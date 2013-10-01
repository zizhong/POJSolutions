#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int x,n=0;
         scanf("%d",&x);
         while(!(x&(1<<n))) n++;
         printf("%d %d\n",x-(1<<n)+1,x+(1<<n)-1);
    }
}
