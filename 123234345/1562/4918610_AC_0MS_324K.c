#include<stdio.h>
#define NMAX 105
char a[NMAX][NMAX];
int n,m;
void mydfs(int x,int y) ;
main()
{
   while(1)
   {
       int i,j,sum=0;
       char c;
       scanf("%d",&m);
       if(!m) break;
       scanf("%d",&n);
       memset(a,'*',NMAX*NMAX*sizeof(char));
       for(i=1;i<=m;i++)
       { 
          for (j=1;j<=n;)
              {
                 c=getchar();
                while(c=='*'||c=='@')
                {
                   a[i][j]=c;
                   j++;
                   c=getchar();
                }
              }                      
       }
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
