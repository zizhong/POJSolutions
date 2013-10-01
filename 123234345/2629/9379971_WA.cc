#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2024;
int f[N][N],t[N][N];
char s1[N],s2[N];
int main()
{
    while(true)
    {
         if(gets(s1+1)==NULL) break;
         if(gets(s2+1)==NULL) break;
         //puts("----"),puts(s1+1),puts(s2+1),puts("****");
         int n=strlen(s1+1),m=strlen(s2+1);
         for(int i=1;i<=n;i++)
              for(int j=1;j<=m;j++)
              {
                    f[i][j]=-1000;
                    t[i][j]=-1;
                    if(s1[i]==s2[j])
                    {
                         f[i][j]=f[i-1][j-1]+1;
                         t[i][j]=1;
                    }
                    if(f[i][j-1]>f[i][j])
                    {
                          f[i][j]=f[i][j-1];
                          t[i][j]=2;
                    }
                    if(f[i-1][j]>f[i][j])
                    {
                          f[i][j]=f[i-1][j];
                          t[i][j]=3;
                    }
              }
         char st[N];
         int top=0;
         int d[4][2]={{0,0},{1,1},{0,1},{1,0}};
         while(n&&m)
         {
               if(t[n][m]==1) st[top++]=s1[n];
               int k=t[n][m];
               n-=d[k][0],m-=d[k][1];
         }
         sort(st,st+top);
         st[top]=0;
         puts(st);
    }
}
