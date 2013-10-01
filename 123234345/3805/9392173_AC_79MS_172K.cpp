#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm> 
using namespace std;
 
typedef double DB;
 
const DB eps=1e-9;
 
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
 
struct point
{
    DB x,y;
}p[110],q[110];
 
DB dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
DB xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int inside_convex(point q,int n,point *p)
{
    int i,s[3]={1,1,1};
    for(i=0;i<n && s[1]|s[2];i++)    s[_sign(xmult(p[(i+1)%n],q,p[i]))]=0;
    return s[1]|s[2];
}
bool isIntersected(point s1,point e1,point s2,point e2)
{
    return ( max(s1.x,e1.x)>=min(s2.x,e2.x)  &&
        max(s2.x,e2.x)>=min(s1.x,e1.x) &&
        max(s1.y,e1.y)>=min(s2.y,e2.y) &&
        max(s2.y,e2.y)>=min(s1.y,e1.y) &&
        xmult(s2,e1,s1)*xmult(e1,e2,s1)>=0 &&
        xmult(s1,e2,s2)*xmult(e2,e1,s2)>=0 );
}
struct cmp
{
    point p;
    cmp(const point &p0) {p=p0;};
    bool operator()(const point &a,const point &b)
    {
        if(fabs(xmult(a,b,p))<eps)   return dist(a,p)<dist(b,p);
        return xmult(a,b,p)>0;
    }
};
int scan(point *p,int n)
{
    int i,k=0,top;
    for(i=1;i<n;i++) if(p[i].y<p[k].y || (fabs(p[i].y-p[k].y)<eps && p[i].x<p[k].x))    k=i;
    swap(p[0],p[k]);
    sort(p+1,p+n,cmp(p[0]));
    top=1;
    for(i=2;i<n;i++)
    {
        while(top && xmult(p[i],p[top],p[top-1])>=0) top--;
        p[++top]=p[i];
    }
    return top+1;
}
bool judge(point *p,int n,point *q,int m)
{
    if(n==1)    p[n++]=p[0];
    if(m==1)    q[m++]=q[0];
    if(n==2 && m==2)    return !isIntersected(p[0],p[1],q[0],q[1]);
    if(m>2)  for(int i=0;i<n;i++) if(inside_convex(p[i],m,q)) return 0;
    if(n>2)  for(int i=0;i<m;i++) if(inside_convex(q[i],n,p)) return 0;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(isIntersected(p[i],p[(i+1)%n],q[j],q[(j+1)%m]))  return 0;
    return 1;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2 && (n||m))
    {
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(int i=0;i<m;i++) scanf("%lf%lf",&q[i].x,&q[i].y);
        if(n*m==0 || n*m==1)
        {
            puts("YES");
            continue;
        }
        n=scan(p,n);
        m=scan(q,m);
        puts(judge(p,n,q,m)?"YES":"NO");
    }
} 