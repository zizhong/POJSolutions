#include<stdio.h>
const int N=102;
int g[N][N];
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//NESW
struct Robot
{
       int x,y,d;
}robot[N];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++)
           for(int j=1;j<=m;j++)
                g[i][j]=0;
        int rt,mv;
        scanf("%d%d",&rt,&mv);
        for(int i=1;i<=rt;i++)
        {
            scanf("%d%d",&robot[i].y,&robot[i].x);
            g[robot[i].x][robot[i].y]=i;
            char s[2];
            scanf("%s",s);
            switch(s[0])
            {
                  case 'N':robot[i].d=0;break;
                  case 'E':robot[i].d=1;break;
                  case 'S':robot[i].d=2;break;
                  case 'W':robot[i].d=3;break;
            }
        }
        int flag=0;
        for(int k=0;k<mv;k++)
        {
             int cur,rp;
             char s[2];
             scanf("%d%s%d",&cur,s,&rp);
             if(!flag)
             {
                  if(s[0]=='L')
                  {
                       robot[cur].d=(robot[cur].d-rp%4+4)%4;
                  }
                  else if(s[0]=='R')
                  {
                       robot[cur].d=(robot[cur].d+rp%4+4)%4;
                  }
                  else
                  {
                      int nx=robot[cur].x,ny=robot[cur].y,nd=robot[cur].d;
                      g[nx][ny]=0;
                      for(int i=0;i<rp;i++)
                      {
                            nx+=d[nd][0],ny+=d[nd][1];
                            if(nx==0||ny==0||nx==n+1||ny==m+1)
                            {
                                  flag=1;
                                  printf("Robot %d crashes into the wall\n",cur);
                                  break;
                            }
                            if(g[nx][ny])
                            {
                                  flag=1;
                                  printf("Robot %d crashes into robot %d\n",cur,g[nx][ny]);
                                  break;
                            }
                      }
                      g[nx][ny]=cur;
                      robot[cur].x=nx,robot[cur].y=ny;
                  }
             }
        }
        if(!flag) puts("OK");
    }
}
