#include<stdio.h>
#include<string.h>
const int N=25;
char s[N][N];
int d[8][2]={{-1,-1},{-1,0,},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int f[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int dfs(int x,int y)
{
    int sum=0;
    s[x][y]='#';
    for(int i=0;i<4;i++)
        if(s[x+f[i][0]][y+f[i][1]]=='.') sum++;
    for(int i=0;i<8;i++)
        if(s[x+d[i][0]][y+d[i][1]]=='X') sum+=dfs(x+d[i][0],y+d[i][1]);
    return sum;
}
int main()
{
    int n,m,tn,tm;
    while(scanf("%d%d%d%d",&n,&m,&tn,&tm),n||m)
    {
        memset(s,'.',sizeof(s));
        for(int i=1;i<=n;i++)
        {
             getchar();
             for(int j=1;j<=m;j++)
                s[i][j]=getchar();
        }
        printf("%d\n",dfs(tn,tm));
    }
}
