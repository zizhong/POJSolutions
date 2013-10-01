#include<stdio.h>
char a[5001],b[5001];
short f[5001][5001];
main()
{
    int n,i,j;
    scanf("%d%s",&n,a);
    strcpy(b,a);
    strrev(b);
    for(i=0;i<n;i++)
         if(a[i]==b[0]) 
         {
           f[i][0]=1;
           for(;i<n;i++)
               f[i][0]=1;
         }
         else f[i][0]=0;
      for(j=0;j<n;j++)
          if(a[0]==b[j])
          {
          f[0][j]=1;
          for(;j<n;j++)
             f[0][j]=1;
          }
          else f[0][j]=0;
    for(i=1;i<n;i++)
      for(j=1;j<n;j++)
          if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
          else f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
    printf("%d\n",n-f[n-1][n-1]);
}
