#include<stdio.h>
#include<string.h>
int g[51][51];
int vst[51][51];
int num,large,n,m;
int dfs(int x,int y)
{         
     if(x<0||x>n||y<0||y>m||vst[x][y]) return 0;
     vst[x][y]=1;
     int area=1,key=g[x][y];
     if(key>=8) key-=8;
     else area+=dfs(x+1,y);
     if(key>=4) key-=4;
     else area+=dfs(x,y+1);
     if(key>=2) key-=2;
     else area+=dfs(x-1,y);
     if(key>=1) key-=1;
     else area+=dfs(x,y-1);
     return area;
}
int main()
{    
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        scanf("%d",&g[i][j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    if(vst[i][j]==0)
    {
        int t=dfs(i,j);
        if(t>large) large=t;
        num++;
    }
    printf("%d\n%d\n",num,large);}
