#include<stdio.h>
int a[101],b[101],f[101][101];
char arr[101],brr[101];
int v[5][5]={0,-3,-4,-2,-1,
             -3,5,-1,-2,-1,
             -4,-1,5,-3,-2,
             -2,-2,-3,5,-2,
             -1,-1,-2,-2,5,             
             };

int trans(char c)
{
    switch(c)
    {
       case 'A':return 1;
       case 'C':return 2;
       case 'G':return 3;
       case 'T':return 4;
    }
}
int maxi(int w,int e,int r)
{
    if(w>e&&w>r) return w;
    if(e>r) return e;
    return r;
}
main()
{
   int t,n,m,i,j,k,max,w,e,r;
   char c;
   scanf("%d",&t);  
   while(t--)
   {
      scanf("%d",&n);
      scanf("%s",arr);
      scanf("%d",&m);
      scanf("%s",brr);
      for(i=1;i<=n;i++)
        {
          c=arr[i-1];
          a[i]=trans(c);             
        }
      printf("a[n]==%d\n",a[n]);
      for(j=1;j<=m;j++)
      {
          c=brr[j-1];
          b[j]=trans(c);
      }
     f[0][0]=0;
     for(i=1;i<=n;i++)
         f[i][0]=f[i-1][0]+v[a[i]][0];
     for(j=1;j<=m;j++)
         f[0][j]=f[0][j-1]+v[0][a[j]];
     for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
           w=f[i-1][j-1]+v[a[i]][b[j]];
           e=f[i-1][j]+v[a[i]][0];
           r=f[i][j-1]+v[0][b[j]];
           f[i][j]=maxi(w,e,r);            
        }
     printf("%d\n",f[n][m]);
   }
}









