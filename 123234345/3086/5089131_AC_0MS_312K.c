#include<stdio.h>
int main()
{
    int t,h;
    scanf("%d",&t);
    h=t;
    while(t--)
    {
       int n,i;
       double sum=0;
       scanf("%d",&n);
       for(i=1;i<=n;i++)
          sum+=i*(i+2)*(i+1)/2.0;
       printf("%d %d %d\n",h-t,n,(int)sum);
    }
}
