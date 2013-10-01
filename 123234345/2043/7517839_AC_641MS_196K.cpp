#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
const int inf=0xffffff;
const double delta=1.0/4000,eps=1e-8;
struct Point
{
       double x,y;
}p[111];
struct Seg
{
       double y1,y2;
}seg[211];
double min(double a,double b){return a>b?b:a;}
double max(double a,double b){return a>b?a:b;}
int cmp(const void *a,const void *b)
{
    Seg *p1=(Seg *)a;
    Seg *p2=(Seg *)b;
    if( p1->y1==p2->y1)
          return p1->y2>p2->y2?1:-1;
    return p1->y1>p2->y1?1:-1;
}
int main()
{
    
    int n;
    while(scanf("%d",&n),n)
    {
          int x1=inf,x2=0;
          double x,y;
          for(int i=0;i<n;i++)
          {
               scanf("%lf%lf",&x,&y);
               p[i].x=x,p[i].y=y;
               if(x<x1) x1=x;
               if(x>x2) x2=x;
          }
          int ans=0;
          for(int xi=x1;xi<x2;xi++)
          {
                int num=0;
                for(int i=0;i<n;i++)
                {
                      Point p1=p[i],p2=p[(i+1)%n];
                      if(p1.x>p2.x){Point pt=p1;p1=p2;p2=pt;}
                      if(p1.x<=xi&&xi+1<=p2.x)
                      {
                          seg[num].y1=(p1.y-p2.y)*(xi-p1.x)/(p1.x-p2.x)+p1.y;
                          seg[num++].y2=(p1.y-p2.y)*(xi+1-p1.x)/(p1.x-p2.x)+p1.y;
                      }
                }
                qsort(seg,num,sizeof(seg[0]),cmp);
                int pre=-inf;
                int tmp=0;
                for(int i=0;i+1<num;i+=2)
                {
                     double t1,t2;
                     t1=ceil(max(seg[i+1].y2,seg[i+1].y1));
                     t2=floor(min(seg[i].y1,seg[i].y2));
                     tmp+=t1-t2;
                     if(t2<=pre)
                         tmp-=(pre-t2);
                     pre=t1;
                }
                if(tmp>0) ans+=tmp;
          }
          printf("%d\n",ans);
    }
    
}
