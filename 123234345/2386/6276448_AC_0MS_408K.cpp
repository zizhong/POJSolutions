#include<stdio.h>
#include<string.h>
char land[111][111];
int d[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void dfs(int x,int y)
{
     if(land[x][y]=='.')  return ;
     land[x][y]='.';
     for(int i=0;i<8;i++)
         dfs(x+d[i][0],y+d[i][1]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(land,'.',sizeof(land));
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
           while((land[i][j]=getchar())!='.'&&land[i][j]!='W');
    int ans=0;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
          if(land[i][j]=='W') ans++,dfs(i,j);
    printf("%d\n",ans);}
