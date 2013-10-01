#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int f[11][30][30],g[11][30][30];
const int dd[][2]={{-1,0},{1,0},{0,1},{0,-1}};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
    int n,d,m;
    while(scanf("%d%d%d",&n,&d,&m),n||m||d)
    {
         memset(f,0,sizeof(f));
         memset(g,0,sizeof(g));
         for(int i=0;i<m;i++)
         {
              int x,y,t;
              scanf("%d%d%d",&x,&y,&t);
              g[t][x+5][y+5]=1;
         }
         for(int t=1;t<=10;t++)
             for(int x1=0;x1<30;x1++)
                for(int y1=0;y1<30;y1++)
                    for(int x2=0;x2<30;x2++)
                       for(int y2=0;y2<30;y2++) if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<=d*d)
                       {
                            int tmp=0,d=gcd(abs(x1-x2),abs(y1-y2));
                            if(abs(x1-x2))
                            for(int k=0;k<=d;k++)
                            {
                                 int nx=x1+k*(x2-x1)/d,ny=y1+k*(y2-y1)/d;
                                 tmp+=g[t][nx][ny];
                                 if(f[t][x1][y1]<f[t-1][nx][ny]+tmp)
                                       f[t][x1][y1]=f[t-1][nx][ny]+tmp;
                            }
                       }
         int ans=0;
         for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(ans<f[10][i][j])
                      ans=f[10][i][j];
         printf("%d\n",ans);
    }
}
