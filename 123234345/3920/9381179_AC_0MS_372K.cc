#include<stdio.h>

int a[220];
int s,t,n;
int dp[220];
const int inf=-1000000000;

int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF && n)
      {
         scanf("%d %d",&s,&t);
         for(i=0;i<220;i++)
           dp[i]=inf;
           
          for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
          
          a[n+1]=0;
          dp[0]=0;
          int pos;
          for(i=0;i<t;i++)
            {
                  // for(k=0;k<=n;k++)
                  //   printf("*%d ",dp[k]);
                  // puts("");
                   
                  for(j=n;j>=i;j--)
                    if(dp[j]!=inf)
                      {
                         for(k=1;k<=s;k++)
                          {
                           if(j+k>n)
                              pos=n+1;
                            else
                              pos=j+k;
                           if(dp[pos]<dp[j]+a[pos]) 
                             dp[pos]=dp[j]+a[pos];                    
                           
                          }
                      } 
                   //for(k=0;k<=n;k++)
                   //  printf("%d ",dp[k]);
                  // puts("");
                                             
            }
         printf("%d\n",dp[n+1]);
                                 
                              
      }

}