#include<stdio.h>
#include<string.h>
char board[101][101];
int main()
{
    int n;
    memset(board,'W',sizeof(board));
    scanf("%d",&n);
    while(n--)
    {
       char cmd[10];
       int x,y,l;
       scanf("%s%d%d%d",cmd,&x,&y,&l);
       switch (cmd[0])
       {
           case 'B':
                for(int i=x;i<x+l;i++)
                   for(int j=y;j<y+l;j++)
                    board[i][j]='B';
                break;
           case 'W':
                for(int i=x;i<x+l;i++)
                   for(int j=y;j<y+l;j++)
                    board[i][j]='W';
                break;
           case 'T':
                int cnt=0;
                for(int i=x;i<x+l;i++)
                   for(int j=y;j<y+l;j++)
                    if(board[i][j]=='B') cnt++;
                printf("%d\n",cnt);
                break;
       }
    }
}
