#include<stdio.h>
const int N=101;
const double eps=1e-8;
int n;
struct Win
{
     double x1,y1,x2,y2,z;
}win[N];
double x[N],y[N];
int comx()
{
    for(int i=1;i<=n;i++)
    {
         int flag=1;
         double y0=win[i].y1,x0=win[i].z;
         for(int j=1;j<=n;j++)
         {
              y[j]=y0*win[j].z/x0;
              if(y[j]+eps<win[j].y1||y[j]-eps>win[j].y2)
              {
                    flag=0;
                    break;
              }
         }
         if(flag) return 0;
         flag=1;
         y0=win[i].y2;
         for(int j=1;j<=n;j++)
         {
              y[j]=y0*win[j].z/x0;
              if(y[j]+eps<win[j].y1||y[j]-eps>win[j].y2)
              {
                    flag=0;
                    break;
              }
         }
         if(flag) return 0;
    }
    return 1;
}
int ok(double x1,double y1,double x2,double y2)
{
    x[0]=x1-y1*(x1-x2)/(y1-y2);
    for(int i=1;i<=n;i++)
    {
         x[i]=x1+(win[i].z-y1)*(y1-y2)/(x1-x2);
         if(x[i]+eps<win[i].x1||x[i]-eps>win[i].x2) return 0;
    }
    return 1;
}
int comy()
{
    for(int i=1;i<=n;i++)
    {
         for(int j=i+1;j<=n;j++)
         {
              if(ok(win[i].x1,win[i].z,win[j].x1,win[j].z)) return 0;
              if(ok(win[i].x1,win[i].z,win[j].x2,win[j].z)) return 0;
              if(ok(win[i].x2,win[i].z,win[j].x1,win[j].z)) return 0;
              if(ok(win[i].x2,win[i].z,win[j].x2,win[j].z)) return 0;
         }
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
          scanf("%lf%lf%lf%lf%lf",&win[i].x1,&win[i].y1,&win[i].x2,&win[i].y2,&win[i].z);
    if(comx()||comy()) 
    {
         puts("UNSOLVABLE");
         return 0;
    }
    puts("SOLUTION");
    printf("%.6lf\n",x[0]);
    for(int i=1;i<=n;i++)
         printf("%.6lf %.6lf %.6lf\n",x[i],y[i],win[i].z);
    scanf("%'d");
}
