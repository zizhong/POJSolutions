#include<stdio.h>
int main()
{
    char s[100001],t[100001];
    while(scanf("%s%s",s,t)!=EOF)
    {
       int i,j,n=0;
       if(strlen(s)<=strlen(t))
       for(i=0,j=0;i<strlen(s)&&j<strlen(t);j++)
           if(s[i]==t[j]) n++,i++;
       if(n==strlen(s)) printf("Yes\n");
       else printf("No\n");
    }
}
