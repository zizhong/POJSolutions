#include<stdio.h>
#include<math.h>
typedef struct { double x,y;} Point;
Point line[100001][2];
int dblcmp(double d)
{
    if(fabs(d)<1e-10) return 0;
    return d>0?1:-1;
}
double det(double x1,double y1,double x2,double y2)
{
       return x1*y2-x2*y1;
}
double cross(Point a,Point b,Point c)
{
       return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int segcross(Point a,Point b,Point c,Point d)
{
     return ((dblcmp(cross(a,c,d))^dblcmp(cross(b,c,d)))==-2 &&
			(dblcmp(cross(c,a,b))^dblcmp(cross(d,a,b)))==-2);
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int i,j;
        for(i=1;i<=n;i++)
           scanf("%lf%lf%lf%lf",&line[i][0].x,&line[i][0].y,&line[i][1].x,&line[i][1].y);
        printf("Top sticks:");
        for(i=1;i<n;i++)
        {
           for(j=i+1;j<=n;j++)
              if(segcross(line[i][0],line[i][1],line[j][0],line[j][1]))
                  break;
           if(j>n)
               printf(" %d,",i);
        }
        printf(" %d.\n",n);
    }
}






