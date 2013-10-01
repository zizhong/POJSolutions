#include<stdio.h>
#include<string.h>
int change(char c)
{
    if(c>='0'&&c<='9') return c-'0';
    if(c>='A'&&c<='Z') return c-'A'+10;
    return c-'a'+36;
}
char s[30002];
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int max=0,i,len=strlen(s),t,sum=0;
        for(i=0;i<len;i++)
        {
           t=change(s[i]);
            if(t>max) max=t;
            sum+=t;
        }
        i=max+1;
        if(i<2) i=2;
        for(;i<=62;i++)
           if(sum%(i-1)==0) break;
        if(i<=62)
           printf("%d\n",i);
        else printf("such number is impossible!\n");
    }
}
