#include<stdio.h>
#include<string.h>
const int N=101;
int map[N][N];
struct Node
{
       int x,y,pre,id;
}q[N*N];
char op[7][10]={"\0","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};
void dfs(int x)
{
     if(q[x].id==0) return ;
     dfs(q[x].pre);
     puts(op[q[x].id]);
}
int main()
{
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    int head=0,tail=0;
    q[tail].x=0,q[tail].y=0,q[tail].pre=-1,q[tail].id=0;
    tail++;
    memset(map,-1,sizeof(map));
    map[0][0]=0;
    int flag=0;
    while(head<tail)
    {
         Node cur=q[head++];
         if(cur.x==C||cur.y==C)
         {
               flag=1;
               //print
               printf("%d\n",map[cur.x][cur.y]);
               dfs(head-1);
               break;
         }
         if(cur.x<A&&map[A][cur.y]==-1)
         {
             q[tail].x=A;
             q[tail].y=cur.y;
             q[tail].pre=head-1;
             q[tail].id=1;
             tail++;
             map[A][cur.y]=map[cur.x][cur.y]+1;
         }
         if(cur.y<B&&map[cur.x][B]==-1)
         {
             q[tail].x=cur.x;
             q[tail].y=B;
             q[tail].pre=head-1;
             q[tail].id=2;
             tail++;
             map[cur.x][B]=map[cur.x][cur.y]+1;
         }
         if(cur.x&&map[0][cur.y]==-1)
         {
             q[tail].x=0;
             q[tail].y=cur.y;
             q[tail].pre=head-1;
             q[tail].id=3;
             tail++;
             map[0][cur.y]=map[cur.x][cur.y]+1;  
         }
         if(cur.y&&map[cur.x][0]==-1)
         {
              q[tail].x=cur.x;
              q[tail].y=0;
              q[tail].pre=head-1;
              q[tail].id=4;
              tail++;
              map[cur.x][0]=map[cur.x][cur.y]+1;
         }
         int nx,ny,tt;
         if(cur.x&&cur.y<B)
         {
              tt=B-cur.y;
              if(tt>=cur.x) nx=0,ny=cur.y+cur.x;
              else nx=cur.x-tt,ny=B;
              if(map[nx][ny]==-1)
              {
                  q[tail].x=nx;
                  q[tail].y=ny;
                  q[tail].pre=head-1;
                  q[tail].id=5;
                  tail++;
                  map[nx][ny]=map[cur.x][cur.y]+1;
              }
         }
         if(cur.x<A&&cur.y)
         {
              tt=A-cur.x;
              if(tt>=cur.y) nx=cur.x+cur.y,ny=0;
              else nx=A,ny=cur.y-tt;
              if(map[nx][ny]==-1)
              {
                   q[tail].x=nx;
                   q[tail].y=ny;
                   q[tail].pre=head-1;
                   q[tail].id=6;
                   tail++;
                   map[nx][ny]=map[cur.x][cur.y]+1;
              }
         }
    }
    if(!flag) puts("impossible");
    scanf("%'d");
}
