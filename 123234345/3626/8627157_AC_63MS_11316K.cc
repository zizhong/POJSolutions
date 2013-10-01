#include<stdio.h>
const int N=1010,BASE=500,d[][2]={{-1,0},{1,0},{0,-1},{0,1}};
int g[N][N];
int v[N][N];
struct Node
{
    int x,y;
}q[N*N];
int main()
{
    int x,y,n;
    scanf("%d%d%d",&x,&y,&n);
    Node ed;
    ed.x=x+BASE,ed.y=y+BASE;
    for(int i=0;i<n;i++)
    {        
        scanf("%d%d",&x,&y);
        g[x+BASE][y+BASE]=1;
    }
    
    int head=0,tail=0;
    q[tail].x=BASE,q[tail].y=BASE;
    tail++;
    v[BASE][BASE]=1;
    while(head<tail)
    {
         Node cur=q[head++];
         if(cur.x == ed.x && cur.y == ed.y)
         {
              printf("%d\n",v[cur.x][cur.y]-1);
              break;
         }
         for(int i=0;i<4;i++)
         {
              x=cur.x+d[i][0],
              y=cur.y+d[i][1];
              if(x<0||x>1000||y<0||y>1000||v[x][y]||g[x][y]) continue;
              v[x][y]=v[cur.x][cur.y]+1;
              q[tail].x=x,q[tail].y=y;
              tail++;
         }
    }
}
