#include <stdio.h>
#include <math.h>

#define precision 0.000000001
typedef struct
{
	double x,y;
}point;

point p[22],q[22];
double max;
int mark,n;

int dblcmp(double d)
{
	if(fabs(d)<precision)
		return 0;
	return (d>0)?1:-1;
}
double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
double cross(point a,point b,point c)
{
	return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int segcross(point a,point b,point c,point d)
{
	if(dblcmp(cross(a,b,c))*dblcmp(cross(a,b,d))<0)
		return 1;
	if(dblcmp(cross(a,b,c))*dblcmp(cross(a,b,d))==0)
		return 2;
	return 0;
}
double point_X(point a,point b,point c,point d)
{
	double e=d.x-c.x,f=b.x-a.x,g=d.y-c.y,k=b.y-a.y,l,m;
	l=e*k;
	m=f*g;
	return (e*f*(c.y-a.y)+l*a.x-m*c.x)/(l-m);
}
int judge(int x,int y,point a,point b)
{
	int i,flag=0,temp;
	double c;
	for(i=0;i<n;i++)
	{
		if(segcross(a,b,p[i],q[i]))
			flag=i;
		else
			break;
	}
	//printf("*** %d %d flag = %d\n",x,y,flag);
	if(mark==n-1)	return 1;
	if(mark<=flag)
	{
		mark=flag;
		temp=segcross(a,b,p[mark],p[mark+1]);
		if(temp==1||(temp==2&&segcross(a,b,q[mark],q[mark+1])==0))
			c=point_X(a,b,p[mark],p[mark+1]);
		else
			c=point_X(a,b,q[mark],q[mark+1]);
		if(c>max)
			max=c;
		//printf("~~ %d,%d,%lf\n",x,y,max);
	}
	return 0;
}

int main()
{
	int i,j;
	while(scanf("%d",&n)&&n)
	{
		for(i=0,mark=0,max=-10e30;i<n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			q[i].x=p[i].x;
			q[i].y=p[i].y-1;
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
			  if(i==j) continue;
              if(judge(i,j,p[i],q[j]))   break;
              if(judge(i,j,q[i],p[j]))   break;
            }
          if(j!=n) break;
		}
		if(i==n)
			printf("%.2lf\n",max);
		else
			printf("Through all the pipe.\n");
	}
	return 0;
}
