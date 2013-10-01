#include<cstdio>
#include<cstdlib>
#include<cstring>
int merge[128];
char s[128];
char vowel[8]="AEIOU";
int main()
{
    for(int i=0;i<5;i++) merge[vowel[i]]=1;
    gets(s);
    for(int i=0;s[i];i++) if(s[i]>='A'&&s[i]<='Z')
    {
         if(merge[s[i]]) s[i]='*';
         else merge[s[i]]=1;
    }
    int cnt=0;
    for(int i=0;s[i];i++) if(s[i]!='*')
         s[cnt++]=s[i];
    s[cnt]=0;
    int p=0;
    while(s[p]==' ') s[p]='*',p++;
    p=cnt-1;
    while(p>=0&&s[p]==' ') s[p--]='*';
    for(p=0;p<cnt-1;p++)
    {
       if(s[p]==' '&&s[p+1]==' ') s[p]='*';
       if(s[p]==' '&&(s[p+1]=='.'||s[p+1]==','||s[p+1]=='?'))
           s[p]='*';
    }
    int len=0;
    for(int i=0;i<cnt;i++) if(s[i]!='*')
        s[len++]=s[i];
    s[len]=0;
    puts(s);
    }
