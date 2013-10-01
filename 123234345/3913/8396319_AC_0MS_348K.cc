#include<stdio.h>
int main()
{
    puts("Gnomes:");
    int n;
    scanf("%d",&n);
    while(n--)
    {
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
          puts((a>=b&&b>=c || a<=b&&b<=c)?"Ordered":"Unordered");
    }
}
