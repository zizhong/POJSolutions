#include<stdio.h>
int a[8]={1,2,4,8,16,32,64,128};
main()
{
   int n=0;
   scanf("%d",&n);
   while(n--)
   {
      int m=0,i;
      char s[35];
      scanf("%s",s);
      for(i=0;i<8;i++)
        if(s[i]=='1') m+=a[7-i];
      printf("%d.",m);
      m=0;
      for(i=8;i<16;i++)
        if(s[i]=='1') m+=a[15-i];
      printf("%d.",m);
      m=0;
      for(i=16;i<24;i++)
        if(s[i]=='1') m+=a[23-i];
      printf("%d.",m);
      m=0;
      for(i=24;i<32;i++)
        if(s[i]=='1')m+=a[31-i];
      printf("%d\n",m);
   }
}
