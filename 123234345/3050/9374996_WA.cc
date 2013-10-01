#include<cstdio>
#include<cstring>
int a[5][5],d[][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool hv[1000000];
int ans;
void dfs(int x,int y,int dep,int val)
{
     if(dep==6) ans+=!hv[val],hv[val]=true;
     else
     {
         for(int k=0;k<4;k++)
         {
             int nx=x+d[k][0],ny=y+d[k][1];
             if(nx<0 || nx>=4 || ny<0 || ny>=4) continue;
             dfs(nx,ny,dep+1,val*10+a[nx][ny]);
         }
     }
}
int main()
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
           scanf("%d",&a[i][j]);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
             dfs(i,j,1,a[i][j]);
    printf("%d\n",ans);
}
