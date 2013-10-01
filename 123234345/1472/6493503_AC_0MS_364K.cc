#include<stdio.h>
#include<string.h>
int deg[11];
char cmd[21];
int main()
{
    int N;
    scanf("%d",&N);
    for(int T=1;T<=N;T++)
    {
         int d;
         memset(deg,0,sizeof(deg));
         scanf("%s",cmd);
         while(1)
         {
              scanf("%s",cmd);
              if(cmd[0]=='E')
                   break;
              if(cmd[0]=='O')
              {
                   scanf("%d",&d);
                   deg[0]+=d;
              }
              if(cmd[0]=='L')
              {
                   int StIn[11][11]={0},StCo[11]={1},top=-1;
                   char subcmd[21];
                   scanf("%s",subcmd);
                   if(subcmd[0]=='n')
                      StIn[++top][1]=1;
                   else
                   {
                       int k;
                       sscanf(subcmd,"%d",&k);
                       StCo[++top]=k;
                       StIn[top][0]=k;
                   }
                   while(top>=0)
                   {
                       scanf("%s",subcmd);
                       switch (subcmd[0])
                       {
                              case 'E':
                                   top--;
                                   break;
                              case 'L':
                                   top++;
                                   scanf("%s",subcmd);
                                   if(subcmd[0]=='n')
                                   {
                                       for(int i=10;i>0;i--)
                                               StIn[top][i]=StIn[top-1][i-1];
                                   }
                                   else
                                   {
                                       int k;
                                       sscanf(subcmd,"%d",&k);
                                       for(int i=10;i>=0;i--)
                                               StIn[top][i]=StIn[top-1][i]*k;
                                   }
                                   break;
                              case 'O':
                                   int k;
                                   scanf("%d",&k);
                                   for(int i=1;i<=10;i++)
                                      deg[i]+=k*StIn[top][i];
                                   deg[0]+=k*StIn[top][0];
                                   break;
                       }
                   }
              }
         }
         printf("Program #%d\nRuntime = ",T);
         int sum=0;
         for(int i=0;i<=10;i++) 
                 sum+=deg[i];
         if(sum==0) printf("0");
         else
         {
             int k=10;
             while(k>=0&&deg[k]==0) k--;
             if(deg[k]>1&&k>0) printf("%d*",deg[k]);
             if(k>0) printf("n");
             if(k>1) printf("^%d",k);
             if(k==0) printf("%d",deg[k]);
             k--;
             while(k>=0)
             {
                  while(k>=0&&deg[k]==0) k--;
		  if (k<0) break;
                  putchar('+');
                  if(deg[k]>1&&k>0) printf("%d*",deg[k]);
                  if(k>0) printf("n");
                  if(k>1) printf("^%d",k);
                  if(k==0) printf("%d",deg[k]);
                  k--;
             }
         }
         printf("\n\n");  
    }
}
