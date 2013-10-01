#include<stdio.h>
#include<stdlib.h>
main()
{
   char s[10]={0};
   int n;
   while(scanf("%s%d",s,&n)!=EOF)
   {
      int i,j,dot=0,ints=0,len=1,c=0;
      int r[100]={0};
      r[0]=1;
      for(i=strlen(s)-1;s[i]=='0';i--);
      for(j=strlen(s)-1;s[j]!='.';j--);
      dot=i-j;
      for(i=strlen(s)-1;s[i]=='0';i--)
          s[i]=0;
      for(i=0;i<strlen(s);i++)
         if(s[i]=='.')
         for(j=i;j<strlen(s);j++)
            s[j]=s[j+1];
      sscanf(s,"%d",&ints);
     for(i=0;i<n;i++)
      {
         for(j=0;j<len;j++)
         {
            r[j]=r[j]*ints+c;
            c=r[j]/10;
            r[j]=r[j]%10;
         }
         while(c!=0)
         {
             r[len++]=c%10;
             c/=10;
         }
     }
     if(r[len]==0) len--;
     if(dot*n>=len+1)
     {
     printf(".");
     for(i=0;dot*n-len-1-i;i++)
        printf("0"); 
     for(i=len;i>=0;i--)
       printf("%d",r[i]); 
     }
     else
     for(i=len;i>=0;i--)
     {
        if(i==dot*n-1) printf(".");
        printf("%d",r[i]);
     }
     printf("\n");
   }
}
