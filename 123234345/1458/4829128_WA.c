#include<stdio.h>
#include<string.h>
main()
{
   char a[1001],b[1001];
   int c[1001][1001]={0};
   int n,m,i,j;
   while((scanf("%s%s",a,b))!=EOF)
   {
      
      
      m=strlen(a);
      n=strlen(b);
      for(i=0;i<m;i++)
          c[i][0]=0;
      for(j=0;j<m;j++)
          c[0][j]=0;
      if(a[0]==b[0]) c[0][0]=1;
      for(i=1;i<m;i++)
      {
         for(j=1;j<n;j++)
         {
            if(a[i]==b[j])
             c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])
               c[i][j]=c[i-1][j];
            else c[i][j]=c[i][j-1];
         }
      }
      printf("%d\n",c[m-1][n-1]);
   }
}
