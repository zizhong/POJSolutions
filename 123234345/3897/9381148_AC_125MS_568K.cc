#include<stdio.h>
#include<math.h>
#include<string.h>
const int N=101;
char g[N][N];
int sx,sy,ex,ey;
double L;
int n;
struct Node
{
       int id;
       double w;
}q[N*N];
int d[4][2]={{0,1},{0,-1},{1,0},{-1,0}},col;
double spfa(double dx)
{
       double map[N][N];
       for(int i=0;i<n;i++)
          for(int j=0;g[i][j];j++)
              map[i][j]=100000000;
       Node st;
       st.id=sx*col+sy;
       st.w=0;
       map[sx][sy]=0;
       int head=0,tail=0;
       q[tail++]=st;
       while(head<tail)
       {
           Node cur=q[head++];
           int x=cur.id/col,y=cur.id%col;
          
           for(int k=0;k<4;k++)
           {
               int nx=x+d[k][0],ny=y+d[k][1];
               if(nx>=0&&nx<n&&ny>=0&&ny<col&&g[nx][ny]!='#')
               {
                      double t=cur.w+(k<2?1:dx);
                      if(t<map[nx][ny])
                      {
                          q[tail].id=nx*col+ny;
                          q[tail].w=t;
                          map[nx][ny]=t;
                          //printf("(%d,%d)\n",nx,ny);
                          tail++;
                      }
                      
               } 
           }
       }
       return map[ex][ey];
}
void slove()
{
     double low=0,high=1000000;
     double mid;
     while(fabs(low - high)>=1e-8)
     {
           mid = (low+high)/2;
           double s=spfa(mid);
           //printf("%lf %lf %lf\n",low,high,s);
           if(L>s) low=mid;
           else high=mid;
     }
     printf("%.3f%%\n",mid*100);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int K=1;K<=T;K++)
    {         
         scanf("%lf%d",&L,&n);
         gets(g[0]);
         for(int i=0;i<n;i++)
             gets(g[i]);
         col=strlen(g[0]);
         //printf("col=%d\n",col);
         for(int i=0;i<=n;i++)
               for(int j=0;g[i][j];j++)
               {
                   if(g[i][j]=='S') sx=i,sy=j;
                   if(g[i][j]=='E') ex=i,ey=j;
               }
         printf("Case #%d: ",K);
         slove();
    }
}