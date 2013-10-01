#include<stdio.h>
#include<string.h>
#define N 400005
char s[N];
int next[N];
void Next()
{
     int q=0,k=-1;
     next[0]=-1;
     while(s[q])
     {
          if(k==-1||s[k]==s[q]) ++k,++q,next[q]=k;
          else k=next[k];
     }
}
int main()
{
    while(scanf("%s",&s)!=EOF)
    {
         Next();
         int n=strlen(s);
         //for(int i=0;i<=n;i++) printf("%d,",next[i]);
         int first=1,t=n;
         int re[N],k=0;
         while(t!=0)
         {
             re[k++]=t;
             t=next[t];
         }
         for(int i=k-1;i>=0;i--)
         {
             if(!first) printf(" ");
             first=0;
             printf("%d",re[i]);
         }
         printf("\n");
    }
}
