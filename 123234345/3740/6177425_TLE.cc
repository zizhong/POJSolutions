#include<stdio.h>
const int N=17,M=301;
int d[N][M];
int n,m;
void Solve()
{
     
     for(int k=1;k<=65535;k++)
     {
           int num[M]={0};
           int flag=1;
           for(int i=1;i<=n&&flag;i++)
           {
                 if((k>>i)&1)
                 {
                      for(int j=0;j<m&&flag;j++)
                      {
                          num[j]+=d[i-1][j];
                          if(num[j]>1) flag=0;
                      }
                 }
           }
           if(flag)
           {int i;
                  for(i=0;i<m;i++)
                     if(num[i]!=1) break;
                  if(i==m)
                  {
                          puts("Yes, I found it");
                          return ;
                  }
           }
     }
     puts("It is impossible");
}
int main()
{    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         
         for(int i=0;i<n;i++)
         {
               for(int j=0;j<m;j++)
               {
                    scanf("%d",&d[i][j]);
               }
         }
         Solve();       
    }
}
