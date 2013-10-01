#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=1001;
struct Point{double x,y;}p[N];
int stack[N];
int left(int a,int b,int c)
{
    return (p[b].x-p[a].x)*(p[c].y-p[b].y) >=
           (p[b].y-p[a].y)*(p[c].x-p[b].x) ;
}
int cmp(const Point a,const Point b)
{
    return a.y==b.y?(a.x<b.x):(a.y<b.y);
}
int convex(int n)
{
    sort(p,p+n,cmp);
    int top=0,i;
    stack[top++]=0,stack[top++]=1;
    for(i=2;i<n;i++)
    {
         stack[top++]=i;
         while(top>2)
         {
             if(left(stack[top-3],stack[top-2],stack[top-1]))
                 break;
             top--;
             stack[top-1]=stack[top];
         }
    }
    int top1=top;
    stack[top++]=n-2;
    for(i=n-3;i>=0;i--)
    {
         stack[top++]=i;
         while(top>=top1+2)
         {
             if(left(stack[top-3],stack[top-2],stack[top-1]))
                break;
             top--;
             stack[top-1]=stack[top];
         }
    }
    return top-1;
}
int collinear(Point a,Point b,Point c)
{
    return (c.x-a.x)*(b.y-a.y)==(b.x-a.x)*(c.y-a.y);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         scanf("%d",&n);
         for(int i=0;i<n;i++)
             scanf("%lf%lf",&p[i].x,&p[i].y);
         int num=convex(n);
         if(n==2||num<n)
         {
              puts("NO");
              continue;
         }
         int v[N]={0};
         for(int i=0;i+2<num+1;i++)
         {
              if(collinear(p[stack[i]],p[stack[i+1]],p[stack[i+2]]))
                 v[i]=1,v[i+1]=1;
         }
         //printf("%d %d\n",p[stack[num]].x,p[stack[num]].y);
         /*for(int i=0;i<num;i++)
             printf("<%I64d %I64d>:%d\n",p[stack[i]].x,p[stack[i]].y,v[i]);*/
         int flag=1;
         for(int i=0;flag&&i<num;i++)
            if(v[i]==0) flag=0;
         puts(flag?"YES":"NO");
    }
}
