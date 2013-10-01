#include<stdio.h>
#include<string.h>
char f[]="VWXYZABCDEFGHIJKLMNOPQRSTU";
int main()
{
    char s[201];
    while(gets(s),s[0]-'E')
    {
          gets(s);
          for(int i=0;s[i];i++)
              if(s[i]>='A'&&s[i]<='Z') s[i]=f[s[i]-'A'];
          puts(s);
          gets(s);
    }
    return 0;
}
