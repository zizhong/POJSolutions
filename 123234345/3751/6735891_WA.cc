#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
         char t[30];
         scanf("%s",t);
         for(int i=5;i<10;i++) putchar(t[i]);
         putchar('/');
         for(int i=0;i<4;i++) putchar(t[i]);
         int h=(t[11]-'0')*10+t[12]-'0',a=0;
         if(h>=0&&h<12) a=0;
         else a=1;
         putchar('-');
         if(a==0) putchar('1'),putchar('2');
         else if(a>12) putchar('0'),putchar(t[12]-2);
         else putchar(t[11]),putchar(t[12]);
         for(int i=13;i<19;i++) putchar(t[i]);
         puts(a?"am":"pm");
    }
}
