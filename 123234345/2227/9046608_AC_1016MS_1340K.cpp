#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct Node
{
       int x,y,h;
       Node(int xx=0,int yy=0,int hh=0):x(xx),y(yy),h(hh){}
       bool operator <(const Node &b)const
       {
            return h>b.h; 
       }
};
priority_queue<Node>q;
int v[310][310],h[310][310];
const int d[][2]={{0,1},{0,-1},{1,0},{-1,0}};
long long ans=0;
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {
           scanf("%d",&h[i][j]);
           if(i==1||j==1||i==n||j==m)
           {
                v[i][j]=1;
                q.push(Node(i,j,h[i][j]));
           }
       }
    while(!q.empty())
    {
          
          Node cur=q.top();//printf("<%d %d %d>\n",cur.x,cur.y,cur.h);
          q.pop();
          queue<Node> q2;
          q2.push(cur);
          while(!q2.empty())
          {
               Node head=q2.front();
               q2.pop();
               for(int k=0;k<4;k++)
               {
                     int x=head.x+d[k][0],y=head.y+d[k][1];
                     if(x==0||y==0||x>n||y>m||v[x][y]) continue;
                     if(h[x][y]>=cur.h)
                     {
                           v[x][y]=1;
                           q.push(Node(x,y,h[x][y]));
                     }
                     else
                     {
                          v[x][y]=1;
                          ans+=cur.h-h[x][y];
                          //printf("%d %d %d\n",cur.h,x,y);
                          h[x][y]=cur.h;
                          q2.push(Node(x,y,cur.h));
                     }
               }
          }
    }
    printf("%lld\n",ans);
    //scanf("%'d");
}
