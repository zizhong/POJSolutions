#include<stdio.h>
#include<math.h>
const int N=201;
struct Point{int x,y;}p[N];
double g[N][N];
int cnt;
int findnum(Point p1)
{
    for(int i=1;i<=cnt;i++)
        if(p1.x==p[i].x&&p1.y==p[i].y) return i;
    p[++cnt]=p1;
    return cnt;
}
double dis(Point p1,Point p2)
{
       return sqrt((double)((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)));
}
int main()
{
   
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
           if(i!=j) g[i][j]=0x3fffffff;
    Point pst,ped,prev,pcur;
    scanf("%d%d%d%d",&pst.x,&pst.y,&ped.x,&ped.y);
    p[1]=pst,p[2]=ped;
    cnt=2;
    int num1,num2;
    while(scanf("%d%d",&prev.x,&prev.y)!=EOF)
    {
         num1=findnum(prev);
         while(scanf("%d%d",&pcur.x,&pcur.y),pcur.x!=-1)
         {
               num2=findnum(pcur);
               g[num2][num1]=g[num1][num2]=dis(p[num1],p[num2])/4;
               num1=num2;
         }
    }
    for(int i=1;i<=cnt;i++)
        for(int j=1;j<=cnt;j++)
            if(dis(p[i],p[j])<g[i][j])
                  g[i][j]=dis(p[i],p[j]);
    double d[N];
    for(int i=1;i<=cnt;i++)
          d[i]=g[1][i];
    int v[N]={0};
    v[1]=1;
    int n=cnt;
    while(1)
    {
         double min=0x3fffffff;
         int tail=-1;
         for(int i=1;i<=n;i++)
             if(v[i]==0&&min>d[i])
                 min=d[i],tail=i;
         if(tail==-1) break;
         v[tail]=1;
         for(int i=1;i<=n;i++)
              if(v[i]==0&&d[i]>g[tail][i]+d[tail])
                     d[i]=g[tail][i]+d[tail];
    }
   printf("%.0lf\n",d[2]*6/1000);
}
