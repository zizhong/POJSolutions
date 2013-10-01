#include<stdio.h>
const int ten[]={1,10,100,1000,10000,100000,1000000};
const int N=11,M=ten[6]+1;
int n;
int g[N][N];
int path[10000000],nn=0;
void dfs(int x)
{
     for(int i=0;i<=9;i++)
          if(g[x][i])
          {
              int k=ten[n-2]-g[x][i];
              --g[x][i];
              path[nn++]=k*10+i;
              dfs((k*10+i));
          }
}
void put(int x)
{
     char s[8];
     int i=0;
     while(x) s[i++]=x%10,x/=10;
     for(int j=i;j<n-1;j++) putchar('0');
     for(i--;i>=0;i--) putchar(s[i]+'0');
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
         for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                g[i][j]=ten[n-2];
         for(int i=0;i<n-1;i++) putchar('0');
         dfs(0);
         for(int i=0;i<nn;i++) put(path[i]);
         puts("");
    }
}
