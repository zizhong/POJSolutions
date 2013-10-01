#include<stdio.h>
#include<string.h>
const int N=17,M=301;
int d[N][M];
int b[M];
int n,m;
void Solve()
{
     int f=1<<n;
     for(int k=1;k<f;k++)
     {
          
           int flag=1,i;
           for(i=0;i<m;i++)
           {
                   int t=k&b[i];
                   if(t==0||t&(t-1))
                   { 
                   flag=0;
                   break;
                   }
           }
           if(flag)
           {
                          puts("Yes, I found it");
                          return ;
           }
     }
     puts("It is impossible");
}
int main()
{    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
         memset(d,0,sizeof(d));
         memset(b,0,sizeof(b));
         for(int i=0;i<n;i++)
         {
               for(int j=0;j<m;j++)
               {
                    scanf("%d",&d[i][j]);
                    d[n][j]+=d[i][j];
               }
         }
         int i;
         for(i=0;i<m;i++)
             if(d[n][i] ==0) break;
         if(i<m)
         {
                puts("It is impossible");
                continue;
         }    
         for(i=0;i<m;i++)
         {
               b[i]=0;
               for(int j=0;j<n;j++)
                    b[i]=b[i]*2+d[j][i];
         }     
         Solve();       
    }
}

