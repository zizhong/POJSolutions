#include<stdio.h>
#include<math.h>
typedef struct tagPoint
{
     int x,y;
 }Point;
 
 int double_area(Point a,Point b,Point c)
 {
     return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
 }
 
 int gcd(int a,int b)
 {
     if(b==0)
         return a;
     return gcd(b,a%b);
}
 
int edgenum(Point a,Point b)
{
    int dx,dy;
    dx=a.x-b.x;
    if(dx<0)
        dx=-dx;
    dy=a.y-b.y;
    if(dy<0)
        dy=-dy;
    return gcd(dx,dy);
}
 
 int main()
 {
     int ab,bc,ca;
     int edge,area,in;
    Point a,b,c;
    while(scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y),a.x||a.y||b.x||b.y||c.x||c.y)
    {
         area=double_area(a,b,c);
         if(area<0)
            area=-area;
        ab=edgenum(a,b);
         bc=edgenum(b,c);
         ca=edgenum(c,a);
        edge=ab+bc+ca;
         in=(area-edge+2)/2;
         printf("%d\n",in);
    }
    return 0;
 }
 
