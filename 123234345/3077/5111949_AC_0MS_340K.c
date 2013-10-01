#include<stdio.h>
main()
{
      int n,i,j;
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
         char s[10]={0};
         scanf("%s",s);
         if(strlen(s)==1) 
         {
         printf("%s\n",s);
         continue;
         }
         for(j=1;j<strlen(s);j++)
         {
             if(s[j]<'4')
               j=strlen(s);
             if(s[j]>'4')
                break;
         }
         if(j<strlen(s))
         {
             if(s[0]=='9') printf("10");
             else printf("%c",s[0]+1);
         }
         else printf("%c",s[0]);
         for(j=1;j<strlen(s);j++)
            printf("0");
         printf("\n");
      }
}
