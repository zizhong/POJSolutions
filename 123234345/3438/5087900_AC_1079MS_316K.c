#include<stdio.h>
#include<string.h>
main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
       char s[1001]={0};
       scanf("%s",s);
       int i,sum=1;
       char cpre=s[0];
       for(i=1;i<strlen(s);i++)
       {
          if(s[i]==cpre)
              sum++;
          else
          {
              printf("%d%c",sum,cpre);
              sum=1;
              cpre=s[i];
          }
       }
       printf("%d%c\n",sum,cpre);
   }
}
