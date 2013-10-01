#include<stdio.h>
#include<string.h>
int main()
{
    char s[258];
    while(scanf("%s",s)!=EOF)
    {
         char t[17];
         int n=strlen(s);
         while(scanf("%s",t),strcmp(t,"END"))
         {
               if(strcmp(t,"NULL")==0) printf("%d %s\n",n,s);
               else
               {
                   int m=strlen(t),flag=0;
                   for(int i=0;i<n&&!flag;i++)
                   {
                         int j=0;
                         for(;j<m&&s[i+j]==t[j];j++) ;
                         if(j>=m) flag=i+1;
                   }
                   if(flag)
                   {
                         printf("%d",flag-1);
                         char str[258]={0};
                         strcpy(str,s);
                         str[flag-1]=0;
                         printf(" %s\n",strlen(str)?str:"NULL");
                   }
                   else printf("%d %s\n",n,s);
               }
         }
    }
}
