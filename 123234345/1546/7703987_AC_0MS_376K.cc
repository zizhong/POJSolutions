#include<stdio.h>
#include<string.h>
char dig[20]={"0123456789ABCDEF"};
int num[128];
int main()
{
    for(int i=0;i<10;i++)
        num[i+'0']=i,num[i+'A']=10+i;
    char s[8];
    int b1,b2;
    while(scanf("%s%d%d",s,&b1,&b2)==3)
    {
          int n=0;
          int len=strlen(s);
          for(int i=0;i<len;i++)
              n=n*b1+num[s[i]];
          char s2[8];
          int ln=0;
          while(n)
          {
               s2[ln++]=dig[n%b2];
               if(ln>7) break;
               n/=b2;
          }
          if(ln>7) puts("  ERROR");
          else
          {
              int t=7-ln;
              while(t--) putchar(' ');
              for(int i=ln-1;i>=0;i--) putchar(s2[i]);
              puts("");
          }
    }
}
