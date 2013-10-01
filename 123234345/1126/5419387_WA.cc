#include<stdio.h>
#include<string.h>
char s[256];
bool find(int a,int b)
{
     if(a>=b&&!(s[a]<='z'&&s[a]>='p')) return true;
     /*bool flag=true;
     for(int i=a;i<=b;i++)
         if(!(s[i]<='z'&&s[i]>='p')) flag=false;
     if(flag) return true;*/
     if(s[a]=='N')
     {
         if(find(a+1,b)) return true;
     }
     if(s[a]=='C'||s[a]=='D'||s[a]=='E'||s[a]=='I')
     {
         for(int i=a+2;i<b;i++)
             if(find(a+1,i)&&find(i+1,b)) return true;
     }
     return false;
}
int main()
{
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s);
        if(find(0,n-1)) printf("YES\n");
        else printf("NO\n");
    }
}
