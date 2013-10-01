#include<stdio.h>
#include<string.h>
const int N=310,d[][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[N][N];
struct Node
{
    int x,y,step;
}q[N*N];
int v[N][N];
int n,m,tail,head;
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
         for(int i=1;i<=n;i++)
            scanf("%s",map[i]+1);
         Node st,ed;
         for(int i=1;i<=n;i++)
              for(int j=1;j<=m;j++)
              {
                  if(map[i][j]=='Y')
                  {
                       st.x=i;
                       st.y=j;
                       st.step=0;
                       map[i][j]='E';
                  }
                  if(map[i][j]=='T')
                  {
                       ed.x=i;
                       ed.y=j;
                       ed.step=-1;
                       map[i][j]='E';
                  }
              }
         q[tail++]=st;
         memset(v,-1,sizeof(v));
         v[st.x][st.y]=0;
         int flag=0;
         while(head<tail)
         {
              Node cur=q[head++];
              if(cur.x==ed.x&&cur.y==ed.y)
              {
                   flag=1;
                   if(ed.step==-1) ed.step=cur.step;
                   else if(ed.step>cur.step) ed.step=cur.step;
              }
              for(int k=0;k<4;k++)
              {
                   int nx=cur.x+d[k][0],ny=cur.y+d[k][1];
                   if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&map[nx][ny]!='S'&&map[nx][ny]!='R')
                   {
                        int nstep=cur.step+(map[nx][ny]=='B'?2:1);
                        if(v[nx][ny]==-1||v[nx][ny]>nstep)
                        {
                             v[nx][ny]=nstep;
                             q[tail].x=nx,q[tail].y=ny,q[tail].step=nstep;
                             tail++;
                             if(map[nx][ny]=='B') map[nx][ny]='E';
                        }
                   }
              }
         }
         if(!flag) puts("-1");
         else printf("%d\n",ed.step);
    }
}
