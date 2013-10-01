#include<stdio.h>
#include<string.h>
int dig[255];
char cdig[63];
int main()
{
    for(int i='0';i<='9';i++) dig[i]=i-'0',cdig[i-'0']=i;
    for(int i=0;i<26;i++) dig[i+'A']=10+i,cdig[10+i]=i+'A';
    for(int i=0;i<26;i++) dig[i+'a']=36+i,cdig[36+i]=i+'a';
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int b1,b2;
         char s[4000],ans[4000];
         scanf("%d%d",&b1,&b2);
         getchar();
         gets(s);
         printf("%d %s\n",b1,s);
         int len1=strlen(s),len2=0;
         while(1)
         {
                 int flag=1,cl=0,rem=0;
                 for(int i=0;i<len1;i++)
                 {
                         int num=dig[s[i]]+rem*b1;
                         if(num<b2)
                         {
                                if(flag) cl++;
                                rem=num,s[i]='0';
                         }
                         else
                         {
                             flag=0;
                             s[i]=cdig[num/b2];
                             rem=num%b2;
                         }
                 }
                 if(cl==len1) {if(rem)ans[len2++]=cdig[rem];break;}
                 ans[len2++]=cdig[rem];
         }
         ans[len2]=0;
         printf("%d ",b2);
         for(int i=len2-1;i>=0;i--) putchar(ans[i]);
         puts("\n");
    }
}
