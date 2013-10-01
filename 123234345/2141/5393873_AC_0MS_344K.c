#include<stdio.h>
#include<string.h>
int main()
{
    char key[27];
    char s[81];
    int i,len;
    scanf("%s",key);
    getchar();
    gets(s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
             s[i]=key[s[i]-'A']-'a'+'A';
        }
        if(s[i]>='a'&&s[i]<='z') s[i]=key[s[i]-'a'];
    }
    puts(s);
}
