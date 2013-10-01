#include<cstdio>
#include<cstring>
struct Point
{
       double x,y;
       void init(){scanf("%lf%lf",&x,&y);}
};
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        Point p1;
        p1.init();
        Point p[2];
        p[0]=p1;
        int x=0;
        printf("%d",n);
        for(int i=1;i<n;i++)
        {
            x^=1;    
            p[x].init();
            printf(" %f %f",(p[0].x+p[1].x)*0.5,(p[0].y + p[1].y)*0.5);
        }
        p[x^1]=p1;
        printf(" %f %f\n",(p[0].x+p[1].x)*0.5,(p[0].y + p[1].y)*0.5);
    }
}
