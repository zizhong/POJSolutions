#include <iostream>
#include <math.h>
#define PI 3.14159265359
using namespace std;
struct   Point   
{   
  double x,y;   
};   
struct   Beeline   
{   
  double   a,b,c;   
};   
int   TwoBeeline(struct   Beeline   l1,struct   Beeline   l2   ,struct   Point   &P)   
{   
  if(fabs(l1.a   *   l2.b  -   l1.b   *   l2.a)<1e-6)   return   -1   ;     
  P.x   =   (l1.c   *   l2.b   -   l1.b   *   l2.c)   /   (l1.b   *   l2.a   -   l1.a   *   l2.b)   ;   
  P.y   =   (l1.a   *   l2.c   -   l1.c   *   l2.a)   /   (l1.b   *   l2.a   -   l1.a   *   l2.b)   ;   
  return   0;   
}   
    
int   Circumcenter(struct   Point   P1,struct   Point   P2,struct   Point   P3,struct   Point   &P)   
{   
  struct   Beeline   l1,l2;   
  l1.a   =   P2.x   -   P1.x   ;   
  l1.b   =   P2.y   -   P1.y   ;   
  l1.c   =   (P1.y   *   P1.y   -   P2.y   *   P2.y   +   P1.x   *   P1.x   -   P2.x   *   P2.x)   *   0.5000   ;   
  l2.a   =   P2.x   -   P3.x   ;   
  l2.b   =   P2.y   -   P3.y   ;   
  l2.c   =   (P3.y   *   P3.y   -   P2.y   *   P2.y   +   P3.x   *   P3.x   -   P2.x   *   P2.x)   *   0.5000   ;   
  return   TwoBeeline(l1,l2,P);   
}
int main()
{
	int i,n,tcase=0;
	Point cp,p[50];
	double r,xmin,xmax,ymin,ymax,disx,disy,angle;
	while (cin>>n)
	{
		if(!n) break;
		tcase++;
		for (i=0;i<3;i++)
		{
			cin>>p[i].x>>p[i].y;
		}
		Circumcenter(p[0],p[1],p[2],cp);
		r=sqrt((cp.x-p[0].x)*(cp.x-p[0].x)+(cp.y-p[0].y)*(cp.y-p[0].y));
		xmax=p[0].x;xmin=p[0].x;ymax=p[0].y;ymin=p[0].y;
		disx=p[0].x-cp.x;disy=p[0].y-cp.y;
		angle=2.0*PI/n;
		for (i=1;i<n;i++)
		{
			p[i].x=cp.x+disx*cos(i*angle)-disy*sin(i*angle);
			p[i].y=cp.y+disx*sin(i*angle)+disy*cos(i*angle);
			if(p[i].x>xmax) xmax=p[i].x;
			if(p[i].x<xmin) xmin=p[i].x;
			if(p[i].y>ymax) ymax=p[i].y;
			if(p[i].y<ymin) ymin=p[i].y;
		}
		printf("Polygon %d: %.3lf\n",tcase,(xmax-xmin)*(ymax-ymin));	
	}
	return 0;
}

