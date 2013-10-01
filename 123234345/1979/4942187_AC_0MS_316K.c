#include<stdio.h>
char tile[22][22];
void dfs(int i,int j)
{
   tile[i][j]='@';
   if(tile[i-1][j]=='.') dfs(i-1,j);
   if(tile[i+1][j]=='.') dfs(i+1,j);
   if(tile[i][j+1]=='.') dfs(i,j+1);
   if(tile[i][j-1]=='.') dfs(i,j-1);
}
main()
{
   int n,m,i,j,count,mi,mj;
   char c;
   while(1)
   {
      scanf("%d%d",&m,&n);
      if(n*m==0) break;
      memset(tile,'#',sizeof(tile)); 
      for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
         {
           c=getchar();
           while(!(c=='.'||c=='#'||c=='@'))
               c=getchar();
           if(c=='@')
           {
           mi=i;mj=j;
           }
           tile[i][j]=c;
         }
      dfs(mi,mj);
      count=0;
      for(i=1;i<=n;i++)
         for(j=1;j<=m;j++)
         if(tile[i][j]=='@')
             count++;
      printf("%d\n",count);
   }
}
