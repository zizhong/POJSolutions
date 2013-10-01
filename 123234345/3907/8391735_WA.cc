#include<stdio.h>
struct Point 
{
       double x,y;
};
double cross(const Point& p1,const Point& p2)
{
       return p1.x*p2.y - p2.x*p1.y;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         if(n<2) puts("0");
         Point p1,p2,p0;
         double area=0.0;
         for(int i=0;i<n;i++)
         {
              scanf("%lf%lf",&p1.x,&p1.y);
              if(i==0)  p0=p1;
              else   area+=cross(p2,p1);
              p2=p1;                    
         }
         area+=cross(p2,p0);
         if(area+1e-9<0) area=-area;
         printf("%.0f\n",area*0.5);
    }
}
