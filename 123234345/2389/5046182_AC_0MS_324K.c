#include<stdio.h>
#include<string.h>
main()
{
   char a[41]={0},b[41]={0};
   scanf("%s%s",a,b);
   int c[100]={0};
   strrev(a);
   strrev(b);
   int i,j,sz=strlen(a)+strlen(b)-1;
   for(i=0;i<strlen(a);i++)
   for(j=0;j<strlen(b);j++)
   {
      c[i+j]+=(a[i]-'0')*(b[j]-'0');
      c[i+j+1]+=c[i+j]/10;
      c[i+j]%=10;
   }
   if(c[sz]==0)  sz--;
   for(i=sz;i>=0;i--)
      printf("%d",c[i]);
   printf("\n");
}
