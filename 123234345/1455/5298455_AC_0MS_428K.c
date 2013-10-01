#include<stdio.h>
int cal(int n)
{
    return n*(n-1)/2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n;
       scanf("%d",&n);
       if(n%2) printf("%d\n",cal(n/2)+cal(n-n/2));
       else printf("%d\n",cal(n/2)*2);              
    }
}
