#include<stdio.h>
struct Point
{
       double x,y;
};
double dot(Point a,Point b)
{
    return a.x*b.y-b.x*a.y;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n>=3)
    {
        Point pst,p1,p2;
        double area=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&p1.x,&p1.y);
            if(i==1)
                pst=p1;
            else
                area+=dot(p2,p1);
            p2=p1;
        }
        area+=dot(p1,pst);
        area=area>0?area:-area;
        double vol;
        scanf("%lf",&vol);
        printf("BAR LENGTH: %.2f\n",vol*2/area);
    }  
}
