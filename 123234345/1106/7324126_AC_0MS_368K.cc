#include<stdio.h>
struct Point
{
       int x,y;
}p[151];
int dis2(Point p1,Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x)+(p1.y - p2.y)*(p1.y - p2.y);
}
int det(int x1,int y1,int x2,int y2){return x1*y2-x2*y1;}
int cross(Point a,Point b,Point c){return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);}
int segcross(Point a,Point b,Point c,Point d)
{
    return cross(a,c,d)*cross(b,c,d)<0&&cross(c,a,b)*cross(d,a,b)<0;
}
int n;
int main()
{
    Point ht;
    double rd;
    while(scanf("%d%d%lf",&ht.x,&ht.y,&rd),rd+1e-8>0)
    {
          scanf("%d",&n);
          for(int i=0;i<n;i++)
             scanf("%d%d",&p[i].x,&p[i].y);
          int ans=0;
          for(int i=0;i<n;i++)
               if(dis2(ht,p[i])<=rd*rd+1e-8)
               {
                    int res1=0,res2=0;
                    for(int j=0;j<n;j++)
                       if(dis2(ht,p[j])<=rd*rd+1e-8)
                       {
                           if(cross(ht,p[i],p[j])<=0) res1++;
                           if(cross(ht,p[i],p[j])>=0) res2++;
                       }
                   if(ans<res1) ans=res1;
                   if(ans<res2) ans=res2; 
               }
          printf("%d\n",ans);
    }
}
