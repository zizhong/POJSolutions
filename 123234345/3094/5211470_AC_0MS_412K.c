#include<stdio.h>
int main()
{
   char s[256];
   while(1)
   {
       int i=0,t=1,sum=0; 
       gets(s);
       if(strcmp(s,"#")==0) break;
       for(i=0;i<strlen(s);i++)
       {
          if(s[i]<'A'||s[i]>'Z') continue;
          sum+=(s[i]-'A'+1)*(i+1);
       }
       printf("%d\n",sum);
   }
}
