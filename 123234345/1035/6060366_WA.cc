#include<stdio.h>
#include<string.h>
char s[10000][16];
int del(char *str,char *cs)
{
    int slen=strlen(str),ilen=strlen(cs);
    if(slen!=ilen-1) return 0;
    int i=0,j;
    for(i=0;i<ilen;i++)
    {
        for(j=0;j<slen;j++)
        {
            char b=cs[j];
            if(j>=i) b=cs[j+1];
            if(str[j]!=b) break;
        }
        if(j==slen) return 1;
    }
    return 0;
}
int ins(char *str,char *cs)
{
    int slen=strlen(str),ilen=strlen(cs);
    if(slen!=ilen+1) return 0;
    int i,j;
    for(i=0;i<slen;i++)
    {
         for(j=0;j<ilen;j++)
         {
              char b=str[j];
              if(j>=i) b=str[j+1];
              if(b!=cs[j]) break;
         }
         if(j==ilen) return 1;
    }
}
int rep(char *str,char *cs)
{
    int slen=strlen(str),ilen=strlen(cs);
    if(slen!=ilen) return 0;
    int num=0;
    for(int i=0;i<slen;i++) if(str[i]!=cs[i]) num++;
    return num==1;
}
int main()
{
    int i=0;
    char str[16];
    while(gets(str),strcmp(str,"#")) strcpy(s[i++],str);
    int n=i;
    while(gets(str),strcmp(str,"#"))
    {
         printf("%s",str);
         for(i=0;i<n;i++)
            if(strcmp(str,s[i])==0)
               break;
         if(i<n)
         {
             puts(" is correct");
             continue;
         }
         putchar(':');
         for(i=0;i<n;i++)
         {
                if(del(str,s[i])||ins(str,s[i])||rep(str,s[i]))
                     printf(" %s",s[i]);
         }
         puts("");         
    } 
}
