#include<stdio.h>
#define NMAX 105
char a[NMAX][NMAX];
int n,m;
void mydfs(int x,int y) ;
main()
{
   int i,j,sum;
   while(1)
   {
       scanf("%d",&m);
       if(!m) break;
       scanf("%d",&n);
       memset(a,'*',NMAX*NMAX*sizeof(char));
       for(i=1;i<=m;i++)
       { 
          if(i!=1)getchar();
          for (j = 1; j <= n; j++)
               a[i][j] = getchar();
            
               
       }
       sum=0;
       for(i=1;i<=m;i++)
          for(j=1;j<=n;j++)
              if(a[i][j]=='@')
             {
               mydfs(i,j);
                sum++;            
             }
       printf("%d\n",sum);
   }
}
void mydfs(int x,int y)
{
   if(a[x][y]=='*') return ;
   a[x][y]='*';
   mydfs(x-1,y-1);mydfs(x-1,y);mydfs(x-1,y+1);
   mydfs(x,y-1);mydfs(x,y+1);
   mydfs(x+1,y-1);mydfs(x+1,y);mydfs(x+1,y+1);
}
