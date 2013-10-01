#include<cstdio>
#include<cstring>
#include<cmath>
double eps=1e-9,pi=3.141;
struct Point
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
}p[1010],cir1,cir2;
double dist2(Point &p1,Point &p2)
{
       return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int n;
int count(double r1,double r2)
{
    int ret=0;
    for(int i=0;i<n;i++) 
          if(dist2(cir1,p[i])>r1+eps && dist2(cir2,p[i])>r2+eps)
            ret++;
    return ret;
}
int min(int a,int b){return a<b?a:b;}
int main()
{
    int T=0;
    while(scanf("%d",&n),n)
    {
         cir1.init(),cir2.init();
         
         double sumarea;
         scanf("%lf",&sumarea);
         for(int i=0;i<n;i++) p[i].init();
         
         int ans=n;
         for(int i=0;i<n;i++)
         {
              double r1=dist2(cir1,p[i]);
              if(sumarea>=pi*r1)
                 ans=min(ans,count(r1,(sumarea-pi*r1)/pi));
              r1=dist2(cir2,p[i]);
              if(sumarea>=pi*r1)
                 ans=min(ans,count((sumarea-pi*r1)/pi,r1)); 
         }
         printf("%d. %d\n",++T,ans);
    }
}
