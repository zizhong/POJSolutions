#include<stdio.h>
int a[26];
int main()
{
    int n,m,p;
    char s[101];
    scanf("%d%d%d",&n,&m,&p);
       for(int i=0;i<n;i++)
       {
            scanf("%s",s);
            for(int i=0;s[i];i++)
                 a[s[i]-'A']++;
       }
    while(p--)
    {
         scanf("%s",s);
         for(int i=0;s[i];i++)
             a[s[i]-'A']--;
    }
    for(int i=0;i<26;i++)
       while(a[i]--)
          putchar(i+'A');
    puts("");
}
