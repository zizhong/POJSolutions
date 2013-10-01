#include<stdio.h>
int main()
{
    char s[100];
    while(gets(s))
    {
         int i=0,n=0,m=0;
         for(i=1;s[i]!='C';i++) n=n*10+s[i]-'0';
         for(i++;s[i];i++) m=m*10+s[i]-'0';
         if(n==0&&m==0) break;
         int c[10]={0};
         m--;
         for(i=0;m>=0;i++)
         {
              c[i]=m%26;
              m/=26;
              m--;
         }
         if(i) i--;
         while(i>=0) putchar(c[i--]+'A');
         printf("%d\n",n);
    }
}
