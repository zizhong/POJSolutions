#include<stdio.h>
const int N=1010;
char map[N][N];
int tmp,n,m;
const int d[][2]={{-1,0},{1,0},{0,1},{0,-1}};
void dfs(int x,int y)
{
     tmp++;
     map[x][y]='.';
     for(int i=0;i<4;i++)
     {
         int nx=x+d[i][0],ny=y+d[i][1];
         if(nx<0||nx>=n||ny<0||ny>=m||map[nx][ny]!='*') continue;
         dfs(nx,ny);
     }
}
int main()
{
    
    while(scanf("%d%d",&m,&n)==2)
    {
         for(int i=0;i<n;i++)
             scanf("%s",map[i]);
         int ans=0;
         for(int i=0;i<n;i++)
             for(int j=0;j<m;j++)
             {
                if(map[i][j]=='*')
                {
                   tmp=0;
                   dfs(i,j);
                   if(tmp>ans) ans=tmp;
                }
             }
         printf("%d\n",ans);
    }
}
