#include<stdio.h>
const int ten[]={1,10,100,1000,10000,100000,1000000};
const int N=11,M=ten[6]+1;
int n;
int g[1000000][10];
int path[1000000],nn=0;
void dfs(int x)
{
     for(int i=0;i<10;i++)
         if(g[x][i])
         {
               g[x][i]=0;
               dfs((x*10+i)%ten[n-1]);
               path[nn++]=i;
         }
}
int main()
{
    while(scanf("%d",&n),n)
    {
         if(n==1)
         {
              puts("0123456789");
              continue;
         }
         nn=0;
         for(int i=0;i<ten[n-1];i++)
               for(int j=0;j<10;j++) 
                   g[i][j]=1;
         for(int i=0;i<n-1;i++) putchar('0');
         dfs(0);
         for(int i=nn-1;i>=0;i--)
               putchar(path[i]+'0');
         puts("");
    }
}
