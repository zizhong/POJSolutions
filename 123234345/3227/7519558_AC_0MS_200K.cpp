#include<stdio.h>
#include<math.h>
const int N=1010;
struct Point
{
       double x,y;
}p[N];
double h;
double dis(Point p1,Point p2)
{
       return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
    int n;    
    while(scanf("%d%lf",&n,&h),n)
    {
          for(int i=0;i<n;i++)
               scanf("%lf%lf",&p[i].x,&p[i].y);
          double ans=dis(p[0],p[1]);
          double k=(p[1].y-h)/p[1].x,x,k1;
          for(int i=1;i+1<n;i++)
          {
               if(i&1)
               {
                    k1=(p[i+1].y-p[i].y)/(p[i+1].x-p[i].x);
                    if(k1<=k) continue; 
                    x=((p[i+1].x-p[i].x)*(h-p[i+1].y)+(p[i+1].y-p[i].y)*p[i+1].x)/(p[i+1].y-p[i].y-k*(p[i+1].x-p[i].x));
                    if(x<p[i].x) x=p[i].x;
                    if(x>p[i+1].x) x=p[i+1].x;
                    ans+=(p[i+1].x-x)*dis(p[i],p[i+1])/(p[i+1].x-p[i].x);
               }else
               {
                    k1=(p[i+1].y-h)/p[i+1].x;
                    if(k1+1e-8<k) continue;
                    x=((p[i+1].x-p[i].x)*(h-p[i+1].y)+(p[i+1].y-p[i].y)*p[i+1].x)/(p[i+1].y-p[i].y-k*(p[i+1].x-p[i].x));
                    if(x<p[i].x) x=p[i].x;
                    if(x>p[i+1].x) x=p[i+1].x;
                    ans+=(p[i+1].x-x)*dis(p[i],p[i+1])/(p[i+1].x-p[i].x);
                    k=k1;
               }
          }
          printf("%.2f\n",ans);
    }
}

