#include <stdio.h>
int main()
{
	double x1,y1,x2,y2,x3,y3,x,y;
	while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x2,&y2,&x3,&y3)!=EOF)
	{
		x = x3 + x1 - x2;
		y = y3 + y1 - y2;
		printf("%.3lf %.3lf\n",x,y);
	}
}
