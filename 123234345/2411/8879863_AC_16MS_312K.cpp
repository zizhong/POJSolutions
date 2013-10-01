#include<stdio.h>
const int N=11;
__int64 f[12][(1<<N)+1];
int n,m;
void dfs(int pos,int state,int x,int orz)
{
     if(pos>=m)
     {
              f[x+1][state]+=f[x][orz];
              return ;
     }
     if(orz&(1<<pos))
     {
             dfs(pos+1,state,x,orz);
             return ;
     }
     if(pos<m-1&&!(orz&(1<<(pos+1))))
     {
             dfs(pos+2,state,x,orz);
     }
     dfs(pos+1,state|(1<<pos),x,orz);
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
          if(n*m%2)
          {
                puts("0");
                continue;
          }
          int t=n>m?m:n;
          n=n+m-t;
          m=t;
          
          for(int i=0;i<=n;i++)
             for(int j=0;j<(1<<m);j++)
                    f[i][j]=0;
          f[0][0]=1;
          for(int i=0;i<n;i++)
          {
               for(int j=0;j<(1<<m);j++)
               {
                     if(f[i][j])
                     {
                           dfs(0,0,i,j);
                     }
               }
          }  
          
          printf("%I64d\n",f[n][0]); 
    }
}

