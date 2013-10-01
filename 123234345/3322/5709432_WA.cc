#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
using namespace std;
const int N= 505;
bool H[N][N],V[N][N],S[N][N];
char map[N][N];
struct St
{
       int step;
       char style;
       int x,y;
};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
         St bg;
         queue<St> q;
         for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
               cin>>map[i][j];
               if(map[i][j]=='X')
                   bg.step=0,bg.style='S',bg.x=i,bg.y=j;
            }
         memset(S,false,sizeof(S)),memset(V,false,sizeof(V)),memset(H,false,sizeof(H));
         S[bg.x][bg.y]=true;
         q.push(bg);
         int flag=0;
         while(q.size())
         {
              St p=q.front();q.pop();
              //printf("%c,%d,%d,%d\n",p.style,p.x,p.y,p.step);
              if(map[p.x][p.y]=='O'&&p.style=='S')
              {
                 printf("%d\n",p.step);
                 flag=1;
                 break;
              }
              St up,down,left,right;              
              if(p.style=='S')
              {
                   if(p.x-2>0&&map[p.x-2][p.y]!='#'&&map[p.x-1][p.y]!='#'&&V[p.x-2][p.y]==false)
                   {
                        V[p.x-2][p.y]=true;
                        up.style='V',up.step=p.step+1,up.x=p.x-2,up.y=p.y;
                        q.push(up);
                   }
                   if(p.x+2<=n&&map[p.x+2][p.y]!='#'&&map[p.x+1][p.y]!='#'&&V[p.x+1][p.y]==false)
                   {
                        V[p.x+1][p.y]=true;
                        down.style='V',down.step=p.step+1,down.x=p.x+1,down.y=p.y;
                        q.push(down);
                   }
                   if(p.y-2>0&&map[p.x][p.y-2]!='#'&&map[p.x][p.y-1]!='#'&&H[p.x][p.y-2]==false)
                   {
                        H[p.x][p.y-2]=true;
                        left.style='H',left.step=p.step+1,left.x=p.x,left.y=p.y-2;
                        q.push(left);
                   }
                   if(p.y+2<=m&&map[p.x][p.y+2]!='#'&&map[p.x][p.y+1]!='#'&&H[p.x][p.y+1]==false)
                   {
                        H[p.x][p.y+1]=true;
                        right.style='H',right.step=p.step+1,right.x=p.x,right.y=p.y+1;
                        q.push(right);
                   }
                   
              }
              else if(p.style=='V')
              {
                   if(p.x-1>0&&map[p.x-1][p.y]!='#'&&map[p.x-1][p.y]!='E'&&S[p.x-1][p.y]==false)
                   {
                        S[p.x-1][p.y]==true;
                        up.style='S',up.step=p.step+1,up.x=p.x-1,up.y=p.y;
                        q.push(up);
                   }
                   if(p.x+2<=n&&map[p.x+2][p.y]!='#'&&map[p.x+2][p.y]!='E'&&S[p.x+2][p.y]==false)
                   {
                        S[p.x+2][p.y]==true;
                        down.style='S',down.step=p.step+1,down.x=p.x+2,down.y=p.y;
                        q.push(down);
                   }
                   if(p.y-1>0&&map[p.x][p.y-1]!='#'&&map[p.x+1][p.y-1]!='#'&&V[p.x][p.y-1]==false)
                   {
                        V[p.x][p.y-1]=true;
                        left.style='V',left.step=p.step+1,left.x=p.x,left.y=p.y-1;
                        q.push(left);
                   }
                   if(p.y+1<=m&&map[p.x][p.y+1]!='#'&&map[p.x+1][p.y+1]!='#'&&V[p.x][p.y+1]==false)
                   {
                        V[p.x][p.y+1]=true;
                        right.style='V',right.step=p.step+1,right.x=p.x,right.y=p.y+1;
                        q.push(right);
                   }
              }
              else
              {
                   if(p.x-1>0&&map[p.x-1][p.y]!='#'&&map[p.x-1][p.y+1]!='#'&&H[p.x-1][p.y]==false)
                   {
                        H[p.x-1][p.y]=true;
                        up.style='H',up.step=p.step+1,up.x=p.x-1,up.y=p.y;
                        q.push(up);
                   }
                   if(p.x+1<=n&&map[p.x+1][p.y+1]!='#'&&map[p.x+1][p.y]!='#'&&H[p.x+1][p.y]==false)
                   {
                        H[p.x+1][p.y]=true;
                        down.style='H',down.step=p.step+1,down.x=p.x+1,down.y=p.y;
                        q.push(down);
                   }
                   if(p.y-1>0&&map[p.x][p.y-1]!='#'&&map[p.x][p.y-1]!='E'&&S[p.x][p.y-1]==false)
                   {
                        S[p.x][p.y-1]=true;
                        left.style='S',left.step=p.step+1,left.x=p.x,left.y=p.y-1;
                        q.push(left);
                   }
                   if(p.y+2<=m&&map[p.x][p.y+2]!='#'&&map[p.x][p.y+2]!='E'&&S[p.x][p.y+2]==false)
                   {
                        S[p.x][p.y+2]=true;
                        right.style='S',right.step=p.step+1,right.x=p.x,right.y=p.y+2;
                        q.push(right);
                   }
              }
              
         }
         if(!flag) printf("Impossible\n");
    }  
}
