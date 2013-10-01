#include<stdio.h>
#include<queue>
using namespace std;
int ds[301][301],tim[301][301],vs[301][301];
bool there(int x,int y)
{
     return x>=0&&y>=0;
}
void visit(int x,int y,int a,int b,queue<int>&q)
{
     if(!there(a,b)||vs[a][b]||(ds[a][b]&&ds[a][b]<=tim[x][y]+1)) return ;
     vs[a][b]=1;
     tim[a][b]=tim[x][y]+1;
     q.push(a);
     q.push(b);
}
int main()
{
    int m;
    scanf("%d",&m);
    int i,j,k;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&j,&k);
        if(!ds[j][k])
        scanf("%d",&ds[j][k]);
        if(there(j-1,k)&&!ds[j-1][k]) ds[j-1][k]=ds[j][k];
        if(there(j+1,k)&&!ds[j+1][k]) ds[j+1][k]=ds[j][k];
        if(there(j,k-1)&&!ds[j][k-1]) ds[j][k-1]=ds[j][k];
        if(there(j,k+1)&&!ds[j][k+1]) ds[j][k+1]=ds[j][k];
    }
    /*for(i=0;i<=5;i++)
    {
       for(j=0;j<=5;j++)
          printf("%d ",ds[i][j]);
       printf("\n");
    }*/
    queue<int >q;
    q.push(0),q.push(0);
    vs[0][0]=1;
    tim[0][0]=0;
    while(q.size())
    {
       int x,y;
       x=q.front();
       q.pop();
       y=q.front();
       q.pop();
       //printf("%d %d %d\n",x,y,tim[x][y]);
       if(ds[x][y]==0)
       {
           printf("%d\n",tim[x][y]);
           return 0;
       }
       visit(x,y,x-1,y,q);
       visit(x,y,x,y-1,q);
       visit(x,y,x+1,y,q);
       visit(x,y,x,y+1,q);
    }
    printf("-1\n");
    return 0;
}
