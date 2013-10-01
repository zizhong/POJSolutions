#include<stdio.h>
char a[11],b[11];
main()
{
      int i;
      while(scanf("%s%s",a,b)&&!(strcmp(a,"0")==0&&strcmp(b,"0")==0))
      {
         int m=0,k=0,times=0;
         strrev(a);
         strrev(b);
         for(i=0;i<strlen(a)||i<strlen(b);i++)
         {
             m=2;
             if(i>=strlen(a)) a[i]=0,m--;
             if(i>=strlen(b)) b[i]=0,m--;
             if((a[i]+b[i]-m*'0'+k)>9)  k=1,times++;
             else k=0;
         }
         if(times==0) printf("No carry operation.\n");
         else if(times==1) printf("1 carry operation.\n");
         else printf("%d carry operations.\n",times);
      }
}
