#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         char a[11];
         int ans[255]={0};
         scanf("%s",&a);
         int len1=strlen(a);
         for(int i=0;i<len1;i++)
         {
               if(a[i]>='a'&&a[i]<='z')
               {
                    if(i>0&&a[i-1]>='0'&&a[i-1]<='9') ans[a[i]]+=a[i-1]-'0';
                    else ans[a[i]]++;
               }
         }
         scanf("%s",&a);
         len1=strlen(a);
         for(int i=0;i<len1;i++)
         {
               if(a[i]>='a'&&a[i]<='z')
               {
                    if(i>0&&a[i-1]>='0'&&a[i-1]<='9') ans[a[i]]+=a[i-1]-'0';
                    else ans[a[i]]++;
               }
         }
         char c[5]={"mcxi"};
         ans['x']+=ans['i']/10;
         ans['i']%=10;
         ans['c']+=ans['x']/10;
         ans['x']%=10;
         ans['m']+=ans['c']/10;
         ans['c']%=10;
         for(int i=0;i<4;i++)
         {
               if(ans[c[i]])
               {
                     if(ans[c[i]]>1)  putchar(ans[c[i]]+'0');
                     putchar(c[i]);
               }
         }
         puts("");
    }
}
