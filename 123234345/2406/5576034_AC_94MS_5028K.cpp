#include<stdio.h>
#include<string.h>
#define N 1000005
char s[N];
int next[N];
void Next()
{
     int q=0,k=-1;
     next[0]=-1;
     for(;s[q];)
     {
         if(k==-1||s[k]==s[q]) ++k,++q,next[q]=k;
         else k=next[k];
     }
}
int main()
{
    while(scanf("%s",s)&&s[0]!='.')
    {
        Next();
        int n=strlen(s);
        int t=n-next[n];
        if(n%t==0)
            printf("%d\n",n/t);
        else printf("1\n");
    }
}
