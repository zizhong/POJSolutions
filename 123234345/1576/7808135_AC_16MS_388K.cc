#include<stdio.h>
#include<string.h>
const int N=81;
char board[N],deck[201][4];
int pos[4],np,nb,nd;
int main()
{
    while(scanf("%d%d%d",&np,&nb,&nd),np)
    {
         scanf("%s",board);
         for(int i=0;i<nd;i++)
             scanf("%s",deck[i]);
         int win=0;
         memset(pos,-1,sizeof(pos));
         for(int i=0;i<nd;i++)
         {
              int flag=strlen(deck[i]);
              for(int j=pos[i%np]+1;j<nb;j++)
              {
                   if(board[j]==deck[i][0]) flag--;
                   if(!flag) {pos[i%np]=j;break;}
              }
              if(pos[i%np]==nb-1||flag)
              {
                  win=1;
                  printf("Player %d won after %d cards.\n",i%np+1,i+1);
                  break;
              }
         }
         if(!win)
         {
              printf("No player won after %d cards.\n",nd);
         }
    }
}
