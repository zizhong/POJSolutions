#include<stdio.h>
#include<string.h>
int main()
{
    char s[16];
    int d[16];
    scanf("%s",s);
    int n=strlen(s);
    for(int i=0;i<n;i++)
        d[i]=s[i]-'0';
    while(scanf("%s",s)==1)
    {
         for(int i=0;i<n;i++)
             d[i]+=s[i]-'0';
    }
    for(int i=0;i<n;i++)
       printf("%d",d[i]%10);
    puts("");
}
