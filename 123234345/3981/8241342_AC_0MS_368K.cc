#include<stdio.h>
#include<string.h>
const int N = 1001;
char s[N];
int main()
{
    while(gets(s))
    {
          int n=strlen(s);
          for(int i=0;i<n;i++)
          {
               if(s[i]=='y'&&s[i+1]=='o'&&s[i+2]=='u')
               {
                    putchar('w');
                    putchar('e');
                    i+=2;
               } else putchar(s[i]);
          }
          puts("");
    }
}
