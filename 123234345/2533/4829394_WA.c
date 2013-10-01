#include<stdio.h>
int a[10001],b[10001];
int c[10001][10001];
int cmp(const void *c,const void *d)
{
    return *(int*)c-*(int *)d;
}
main()
{
   
   int n,i,j,k;
   while(scanf("%d",&n)!=EOF)
   {
      for(i=0;i<n;i++)
         scanf("%d",&a[i]);
      for(i=0;i<n;i++)
          b[i]=a[i];
      qsort(b,n,sizeof(b[0]),cmp);
      for(i=0;i<n;i++)
         if(a[i]==b[0]) 
         {
           c[i][0]=1;
           for(;i<n;i++)
               c[i][0]=1;
         }
         else c[i][0]=0;
      for(j=0;j<n;j++)
          if(a[0]==b[j])
          {
          c[0][j]=1;
          for(;j<n;j++)
             c[0][j]=1;
          }
          else c[0][j]=0;
      for(i=1;i<n;i++)
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
      printf("%d\n",c[n-1][n-1]);
   }
}
