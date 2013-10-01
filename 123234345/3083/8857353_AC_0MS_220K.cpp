#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=64;
char map[N][N];
int n,m;
const int d[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int dfs(int x,int y,int p,int delta) //p表示往哪个方向走 
{
    //printf("<%d %d %d %d> \t",x,y,p,delta);
    //system("pause");
    if(map[x][y]=='E') return 0;
    for(int i=-1;i<3;i++)
    {
         int nx=x+d[(i*delta+p+4)%4][0],ny=y+d[(i*delta+4+p)%4][1];
         if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]=='#') continue;
         return 1+dfs(nx,ny,(i*delta+p+4)%4,delta);
    }
}
int bfs(int x,int y)
{
    int v[N][N];
    memset(v,-1,sizeof(v));
    int q[N*N][2],head=0,tail=0;
    v[x][y]=0;
    q[tail][0]=x,q[tail++][1]=y;
    while(head!=tail)
    {
          int cx=q[head][0],cy=q[head][1];
          head++;
          if(map[cx][cy]=='E')
               return v[cx][cy];
          for(int i=0;i<4;i++)
          {
              int nx=d[i][0]+cx,ny=d[i][1]+cy;
              if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]=='#'||v[nx][ny]>=0) continue;
              v[nx][ny]=v[cx][cy]+1;
              q[tail][0]=nx;
              q[tail][1]=ny;
              tail++;
          }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++)
            scanf("%s",map[i]); 
        int sx,sy,sp;
        for(int i=0;i<n;i++)
        {
            if(map[i][0]=='S')  sx=i,sy=0,sp=1;
            if(map[i][m-1]=='S') sx=i,sy=m-1,sp=3;
        }
        for(int i=0;i<m;i++)
        {
            if(map[0][i]=='S') sx=0,sy=i,sp=2;
            if(map[n-1][i]=='S') sx=n-1,sy=i,sp=0;
        }
        printf("%d %d %d\n",dfs(sx,sy,sp,1)+1,dfs(sx,sy,sp,-1)+1,bfs(sx,sy)+1);
    }
}
