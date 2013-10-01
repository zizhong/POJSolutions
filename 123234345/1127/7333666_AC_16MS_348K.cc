#include<stdio.h>
#include<math.h>
#include<stdlib.h>
const int N=15;
struct Point {int x,y;}p[N][2];
int g[N][N];
int det(int x1,int y1,int x2,int y2){return x1*y2-x2*y1;}
int cross(Point a,Point b,Point c){return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);}
int segcross(Point a,Point b,Point c,Point d)
{
    return cross(a,c,d)*cross(b,c,d)<0&&cross(c,a,b)*cross(d,a,b)<0;
}
double dis2(Point a,Point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=1;i<=n;i++)
            for(int j=0;j<=1;j++)
                scanf("%d%d",&p[i][j].x,&p[i][j].y);
         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=(i==j);
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
             {
                if(segcross(p[i][0],p[i][1],p[j][0],p[j][1]))
                    g[i][j]=1;
                if((dis2(p[i][0],p[j][1])+dis2(p[i][1],p[j][1])-dis2(p[i][0],p[i][1]))<1e-8) g[i][j]=1;
                if((dis2(p[i][0],p[j][0])+dis2(p[i][1],p[j][0])-dis2(p[i][0],p[i][1]))<1e-8) g[i][j]=1;
                if((dis2(p[i][0],p[j][0])+dis2(p[i][0],p[j][1])-dis2(p[j][0],p[j][1]))<1e-8) g[i][j]=1;
                if((dis2(p[i][1],p[j][0])+dis2(p[i][1],p[j][1])-dis2(p[j][0],p[j][1]))<1e-8) g[i][j]=1;
             }
         //printf("%d %d %d\n",dis2(p[5][0],p[3][0]),dis2(p[5][1],p[3][0]),dis2(p[5][1],p[5][0]));
         for(int k=1;k<=n;k++)
              for(int i=1;i<=n;i++)
                  for(int j=1;j<=n;j++)
                      if(g[i][k]&g[k][j]) g[i][j]=1;
         int x,y;
         while(scanf("%d%d",&x,&y),x)
         {
              puts(g[x][y]?"CONNECTED":"NOT CONNECTED");
         }
    }
}
