#include<stdio.h>
char a[21][21];
char code[11]={"9123456789"};
main()
{
      int n,s,i,j;
      scanf("%d%d",&n,&s);
      memset(a,' ',sizeof(a));
      for(i=0;i<n;i++)
         for(j=0;j<=i;j++)
         {
            a[j][i]=code[s%9];
            s++;
         }
      for(i=0;i<n;i++)
      {
         for(j=0;j<n;j++)
         {
         if(j) printf(" ");
         printf("%c",a[i][j]);
         }
         printf("\n");
      }}
