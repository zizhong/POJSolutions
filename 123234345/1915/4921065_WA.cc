#include<iostream>
#include<queue>
using namespace std;
int visit[301][301],a[301][301],d[301][301];
int n;
bool zai(int x,int y)
{
  return x>=0&&x<=n&&y>=0&&y<=n;
}
void vst(int x,int y,int a,int b,queue< int > &q)
{
   if(!zai(x,y)||visit[x][y]!=0) return ;
   visit[x][y]=1;
   d[x][y]=d[a][b]+1;
   q.push(x);
   q.push(y);
}
int main()
{
   int t;
   cin>>t;
   while(t--)
  {   
      int i,j,mi,mj;   
      cin>>n>>i>>j>>mi>>mj;
      if(i==mi&&j==mj)
      {
         printf("0\n");
         break;
      }
      queue <int > q ;
      int r,l;
      for(r=0;r<=300;r++)
         for(l=0;l<=300;l++)
         {
            visit[r][l]=0;
            d[r][l]=0;
         }
      q.push(i);
      q.push(j);
      visit[i][j]=1;   
      while(q.size())
     {
         int x,y;
         x=q.front();
         q.pop();
         y=q.front();
         q.pop();
          vst(x-2,y-1,x,y,q);vst(x-2,y+1,x,y,q);
          vst(x-1,y-2,x,y,q);vst(x-1,y+2,x,y,q);
          vst(x+1,y-2,x,y,q);vst(x+1,y+2,x,y,q);
          vst(x+2,y-1,x,y,q);vst(x+2,y+1,x,y,q);
          if(d[mi][mj])
          {
             printf("%d\n",d[mi][mj]);
             break;
          }
     }
  }
}
