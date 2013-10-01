#include<stdio.h>
bool dig(char c){return c>='0'&&c<='9';}
int main()
{
    int a,b,sum;
    while(1)
    {
         int c=0;
         while(c!=-1&&!dig(c)) c=getchar();
         if(c==-1) break;
         a=c-'0';
         int ten=1;
         while(dig(c=getchar()))
         {
             ten*=10;
             a+=ten*(c-'0');
         }
         while(!dig(c=getchar())) ;
         b=c-'0';
         ten=1;
         while(dig(c=getchar()))
         {
             ten*=10;
             b+=ten*(c-'0');
         }
         while(!dig(c=getchar())) ;
         sum=c-'0';
         ten=1;
         while(dig(c=getchar()))
         {
             ten*=10;
             sum+=ten*(c-'0');
         }
         puts(sum==a+b?"True":"False");
    }
}
