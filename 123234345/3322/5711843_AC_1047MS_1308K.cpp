#include<stdio.h>
#include<string.h>
const int N=505;
const int K=10000;
bool H[N][N],V[N][N],S[N][N];
char map[N][N];
struct St
{
       int step;
       char style;
       int x,y;
}q[K];
int head,last;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
         St bg;
         int num=0;
         head=last=0;
         for(int i=1;i<=n;i++)
         {
            getchar();
            for(int j=1;j<=m;j++)
            {
               
               map[i][j]=getchar();   
               if(map[i][j]=='X'&&num==0)
               {
                   bg.step=0,bg.style='S',bg.x=i,bg.y=j;
                   num++;
                   continue;
               }
               if(map[i][j]=='X'&&num==1)
               {
                   if(i==bg.x) bg.style='H';
                   else bg.style='V';
               }
               V[i][j]=H[i][j]=S[i][j]=0;
            }
         }
         if(num==0) S[bg.x][bg.y]=true;
         else if(bg.style=='H') H[bg.x][bg.y]=true;
         else V[bg.x][bg.y]=true;
         q[(last++)%K]=bg;
         int flag=0;
         while(head!=last)
         {
              St p=q[(head++)%K];
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
                        q[(last++)%K]=up;
                   }
                   if(p.x+2<=n&&map[p.x+2][p.y]!='#'&&map[p.x+1][p.y]!='#'&&V[p.x+1][p.y]==false)
                   {
                        V[p.x+1][p.y]=true;
                        down.style='V',down.step=p.step+1,down.x=p.x+1,down.y=p.y;
                        q[(last++)%K]=down;
                   }
                   if(p.y-2>0&&map[p.x][p.y-2]!='#'&&map[p.x][p.y-1]!='#'&&H[p.x][p.y-2]==false)
                   {
                        H[p.x][p.y-2]=true;
                        left.style='H',left.step=p.step+1,left.x=p.x,left.y=p.y-2;
                        q[(last++)%K]=left;
                   }
                   if(p.y+2<=m&&map[p.x][p.y+2]!='#'&&map[p.x][p.y+1]!='#'&&H[p.x][p.y+1]==false)
                   {
                        H[p.x][p.y+1]=true;
                        right.style='H',right.step=p.step+1,right.x=p.x,right.y=p.y+1;
                        q[(last++)%K]=right;
                   }
                   
              }
              else if(p.style=='V')
              {
                   if(p.x-1>0&&map[p.x-1][p.y]!='#'&&map[p.x-1][p.y]!='E'&&S[p.x-1][p.y]==false)
                   {
                        S[p.x-1][p.y]==true;
                        up.style='S',up.step=p.step+1,up.x=p.x-1,up.y=p.y;
                        q[(last++)%K]=up;
                   }
                   if(p.x+2<=n&&map[p.x+2][p.y]!='#'&&map[p.x+2][p.y]!='E'&&S[p.x+2][p.y]==false)
                   {
                        S[p.x+2][p.y]==true;
                        down.style='S',down.step=p.step+1,down.x=p.x+2,down.y=p.y;
                        q[(last++)%K]=down;
                   }
                   if(p.y-1>0&&map[p.x][p.y-1]!='#'&&map[p.x+1][p.y-1]!='#'&&V[p.x][p.y-1]==false)
                   {
                        V[p.x][p.y-1]=true;
                        left.style='V',left.step=p.step+1,left.x=p.x,left.y=p.y-1;
                        q[(last++)%K]=left;
                   }
                   if(p.y+1<=m&&map[p.x][p.y+1]!='#'&&map[p.x+1][p.y+1]!='#'&&V[p.x][p.y+1]==false)
                   {
                        V[p.x][p.y+1]=true;
                        right.style='V',right.step=p.step+1,right.x=p.x,right.y=p.y+1;
                        q[(last++)%K]=right;
                   }
              }
              else
              {
                   if(p.x-1>0&&map[p.x-1][p.y]!='#'&&map[p.x-1][p.y+1]!='#'&&H[p.x-1][p.y]==false)
                   {
                        H[p.x-1][p.y]=true;
                        up.style='H',up.step=p.step+1,up.x=p.x-1,up.y=p.y;
                        q[(last++)%K]=up;
                   }
                   if(p.x+1<=n&&map[p.x+1][p.y+1]!='#'&&map[p.x+1][p.y]!='#'&&H[p.x+1][p.y]==false)
                   {
                        H[p.x+1][p.y]=true;
                        down.style='H',down.step=p.step+1,down.x=p.x+1,down.y=p.y;
                        q[(last++)%K]=down;
                   }
                   if(p.y-1>0&&map[p.x][p.y-1]!='#'&&map[p.x][p.y-1]!='E'&&S[p.x][p.y-1]==false)
                   {
                        S[p.x][p.y-1]=true;
                        left.style='S',left.step=p.step+1,left.x=p.x,left.y=p.y-1;
                        q[(last++)%K]=left;
                   }
                   if(p.y+2<=m&&map[p.x][p.y+2]!='#'&&map[p.x][p.y+2]!='E'&&S[p.x][p.y+2]==false)
                   {
                        S[p.x][p.y+2]=true;
                        right.style='S',right.step=p.step+1,right.x=p.x,right.y=p.y+2;
                        q[(last++)%K]=right;
                   }
              }
              
         }
         if(!flag) printf("Impossible\n");
    }  
}

