#include<stdio.h>
int h[101][101],f[101][101];
int maxi(int a,int b,int c,int d)
{
     int i,arr[4]={a,b,c,d},mx=0;
     for(i=0;i<4;i++)
     {
         mx=mx<arr[i]?arr[i]:mx;
     }
     return mx;
}
main()
{
   int mx,n,m,j,i,shang,xia,zuo,you,t;
   scanf("%d%d",&n,&m);
   for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        scanf("%d",&h[i][j]);
   t=m>n?m:n;
   while(t--)
  { for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
         if(i-1==0||h[i][j]<=h[i-1][j]) shang=0;
         else shang=f[i-1][j];
         if(j-1==0||h[i][j]<=h[i][j-1]) zuo=0;
         else zuo=f[i][j-1];
         if(j==m||h[i][j]<=h[i][j+1]) you=0;
         else you=f[i][j+1];
         if(i==n||h[i][j]<=h[i+1][j]) xia=0;
         else xia=f[i+1][j];
         f[i][j]=maxi(shang,xia,zuo,you)+1;
      } 
      for(i=1;i<=n;i++)
         for(j=m;j>=1;j--)
         {
            if(i-1==0||h[i][j]<=h[i-1][j]) shang=0;
         else shang=f[i-1][j];
         if(j-1==0||h[i][j]<=h[i][j-1]) zuo=0;
         else zuo=f[i][j-1];
         if(j==m||h[i][j]<=h[i][j+1]) you=0;
         else you=f[i][j+1];
         if(i==n||h[i][j]<=h[i+1][j]) xia=0;
         else xia=f[i+1][j];
         f[i][j]=maxi(shang,xia,zuo,you)+1;
         }
        for(i=n;i>=1;i--)
        for(j=1;j<=m;j++)
        {
          if(i-1==0||h[i][j]<=h[i-1][j]) shang=0;
         else shang=f[i-1][j];
         if(j-1==0||h[i][j]<=h[i][j-1]) zuo=0;
         else zuo=f[i][j-1];
         if(j==m||h[i][j]<=h[i][j+1]) you=0;
         else you=f[i][j+1];
         if(i==n||h[i][j]<=h[i+1][j]) xia=0;
         else xia=f[i+1][j];
         f[i][j]=maxi(shang,xia,zuo,you)+1;
        }
    for(i=n;i>=1;i--)
      for(j=m;j>=1;j--)
      {
         if(i-1==0||h[i][j]<=h[i-1][j]) shang=0;
         else shang=f[i-1][j];
         if(j-1==0||h[i][j]<=h[i][j-1]) zuo=0;
         else zuo=f[i][j-1];
         if(j==m||h[i][j]<=h[i][j+1]) you=0;
         else you=f[i][j+1];
         if(i==n||h[i][j]<=h[i+1][j]) xia=0;
         else xia=f[i+1][j];
         f[i][j]=maxi(shang,xia,zuo,you)+1;
      } 
       
}
   mx=0;
   for(i=1;i<=n;i++)
     { for(j=1;j<=m;j++)
      {
        
         mx=mx<f[i][j]?f[i][j]:mx; 
      }
    
     }
  printf("%d\n",mx);
}
