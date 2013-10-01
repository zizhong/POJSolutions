#include<stdio.h>
main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      char s1[5],s2[5];
      scanf("%s%s",s1,s2);
      int a=0,b=0,i,j;
      for(i=0;i<4;i++)
         for(j=0;j<4;j++)
         if(s1[i]==s2[j])
           a++;
      for(i=0;i<4;i++)
        if(s1[i]==s2[i])
          b++;
      printf("%dA%dB\n",b,a-b);
   }
}
