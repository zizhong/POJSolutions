#include<stdio.h>
#include<math.h>
double max(double a,double b)
{
       return a>b?a:b;
}
struct Point
{
       double x,y;
};
int dblcmp(double a)
{
    if(fabs(a)<1e-8) return 0;
    return a>0?1:-1;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        Point r[4];
        r[0].x=x3+x4-max(x3,x4),r[0].y=y3+y4-max(y3,y4);
        r[1].x=max(x3,x4),r[1].y=y3+y4-max(y3,y4);
        r[2].x=max(x3,x4),r[2].y=max(y3,y4);
        r[3].x=x3+x4-max(x3,x4),r[3].y=max(y3,y4);
        
        if(dblcmp((y2-y1)*(r[0].x-x1)-(r[0].y-y1)*(x2-x1))==
           dblcmp((y2-y1)*(r[1].x-x1)-(r[1].y-y1)*(x2-x1))&&
           dblcmp((y2-y1)*(r[0].x-x1)-(r[0].y-y1)*(x2-x1))==
           dblcmp((y2-y1)*(r[2].x-x1)-(r[2].y-y1)*(x2-x1))&&
           dblcmp((y2-y1)*(r[0].x-x1)-(r[0].y-y1)*(x2-x1))==
           dblcmp((y2-y1)*(r[3].x-x1)-(r[3].y-y1)*(x2-x1))&&
           dblcmp((y2-y1)*(r[0].x-x1)-(r[0].y-y1)*(x2-x1))!=0)
           {
              printf("F\n");
              continue;
           }
        if((y1+y2-max(y1,y2))>r[2].y||
           (max(y1,y2)<r[0].y)||
           (x1+x2-max(x1,x2))>r[2].x||
           (max(x1,x2)<r[0].x))
           {
              printf("F\n");
              continue;
           }
        printf("T\n");
    }
}

