#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int N=12;
__int64 f[N+2][1<<N];
int n,m;
int i,p;
void dfs(int j,int o)
{
     if(j==m)
     {
          f[i+1][o]+=f[i][p];
          return ;
     }
     if(p&(1<<j)) {dfs(j+1,o);return ;}
     dfs(j+1,o|(1<<j));
     if(j+2>m) return ;
     if(!(p&(1<<j+1))) dfs(j+2,o);
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
         if(n*m%2){puts("0");continue;}
         memset(f,0,sizeof(f));
         f[0][0]=1;
         if(n<m)
         {
              int t=n;
              n=m;
              m=t;
         }
         for(i=0;i<n;i++)
              for(p=0;p<(1<<m);p++) if(f[i][p]>0)
              {
                   dfs(0,0);
              }
         cout<<f[n][0]<<endl;
    }
}
