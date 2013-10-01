#include<stdio.h>
#include<string.h>
const int N=5;
int d[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int maze[N][N];
int vst[N][N];
struct Node
{
       int x,y,pre;
}q[N*N];
bool ok(int x,int y)
{
     if(x<0||x>N-1||y<0||y>N-1||maze[x][y]||vst[x][y]) return false;
     return true; 
}
void print(int x)
{
     if(x==-1) return ;
     print(q[x].pre);
     printf("(%d, %d)\n",q[x].x,q[x].y);
}
int main()
{
    for(int i=0;i<N;i++)
       for(int j=0;j<N;j++)
          scanf("%d",&maze[i][j]);
    int head=0,tail=0;
    Node cur;
    cur.x=0,cur.y=0,cur.pre=-1;
    q[tail++]=cur;
    while(head<tail)
    {
         cur=q[head++];
         if(cur.x==N-1&&cur.y==N-1)
         {
               print(head-1);
               break;
         }
         for(int i=0;i<4;i++)
         {
               if(ok(cur.x+d[i][0],cur.y+d[i][1]))
               {
                     vst[cur.x+d[i][0]][cur.y+d[i][1]]=1;
                     q[tail].x=cur.x+d[i][0];
                     q[tail].y=cur.y+d[i][1];
                     q[tail].pre=head-1;
                     tail++;
               }
         }
    }
    scanf("%'d");
}
