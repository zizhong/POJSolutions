#include<stdio.h>
char stack[2001];
int top=-1;
int main()
{
    char s[2001];
    int T=1;
    while(scanf("%s",s),s[0]!='-')
    {
         top=-1;
         for(int i=0;s[i];i++)
         {
              if(top==-1) stack[++top]=s[i];
              else if(stack[top]=='{'&&s[i]=='}') top--;
              else stack[++top]=s[i];
         }
         int a=0,b=0;
         for(int i=0;i<=top;i++)
               if(stack[i]=='{')
                   a++;
               else b++;
         int ans=0;
         if(a&1) ans=2,a--,b--;
         ans+=a/2+b/2;
         printf("%d. %d\n",T++,ans);
    }
    
}