#include<stdio.h>
const int ten[]={1,10,100,1000,10000,100000,1000000};
const int N=11,M=ten[6]+1;
int n;
int g[1000000];
int st[1000000+10],nst=0;
int path[1000000+10],nn=0;
void Tour(int v)
{
     while(g[v]<10)
     {
          int w=v*10+g[v];
          st[nst++]=w;
          ++g[v];
          v=w%ten[n-1];
     }
}
void dfs()
{
     int v=0;
     nn=nst=0;
     while(Tour(v),nst)
     {
          v=st[--nst];
          path[nn++]=v%10;
          v/=10;
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
         for(int i=0;i<ten[n-1];i++) g[i]=0;
         for(int i=0;i<n-1;i++) putchar('0');
         dfs();
         for(int i=nn-1;i>=0;i--)
               putchar(path[i]+'0');
         puts("");
    }
}
