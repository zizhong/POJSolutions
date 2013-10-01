#include<stdio.h>
#include <math.h>
int main()
{
	double x,y,c,w,l,r,lh,rh,temp;
	while (scanf("%lf%lf%lf",&x,&y,&c)!=EOF)
	{
		r=x>y? y:x;
		l=0;
		while (1)
		{
			w=(l+r)/2;
			lh=sqrt(x*x-w*w);
			rh=sqrt(y*y-w*w);
			temp=lh/(lh+rh)*rh;
			if(fabs(c-temp)<1e-4)
				break;
			else if(c-temp<0) l=w;
			else r=w;
		}
		printf("%.3f\n",w);
	}
}
