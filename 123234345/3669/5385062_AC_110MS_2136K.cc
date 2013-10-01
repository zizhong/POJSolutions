#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int ds[401][401],tim[401][401],vs[401][401];
bool there(int x,int y)
{
     return x>=0&&y>=0;
}
void visit(int x,int y,int a,int b,queue<int>&q)
{
     if(!there(a,b)||vs[a][b]||(ds[a][b]>0&&ds[a][b]<=tim[x][y]+1)) return ;
     vs[a][b]=1;
     tim[a][b]=tim[x][y]+1;
     q.push(a);
     q.push(b);
}
int main()
{
    int m;
    scanf("%d",&m);
    int i,j,k,t;
    memset(ds,-1,sizeof(ds));
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&j,&k);
        scanf("%d",&t);
        if(ds[j][k]==-1||ds[j][k]>t) ds[j][k]=t;
        if(there(j-1,k)&&(ds[j-1][k]==-1||ds[j-1][k]>t)) ds[j-1][k]=t;
        if(there(j+1,k)&&(ds[j+1][k]==-1||ds[j+1][k]>t)) ds[j+1][k]=t;
        if(there(j,k-1)&&(ds[j][k-1]==-1||ds[j][k-1]>t)) ds[j][k-1]=t;
        if(there(j,k+1)&&(ds[j][k+1]==-1||ds[j][k+1]>t)) ds[j][k+1]=t;
    }
    /*for(i=0;i<=10;i++)
    {
       for(j=0;j<=10;j++)
          printf("%4d",ds[i][j]);
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
       if(ds[x][y]==-1)
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
