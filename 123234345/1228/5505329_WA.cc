#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point 
{
       int x,y;
}p[1001];
int stack[1009];
int cmp(point a,point b)
{
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
int left(int a,int b,int c)
{
    return (p[a].x-p[b].x)*(p[b].y-p[c].y)>=(p[a].y-p[b].y)*(p[b].x-p[c].x);
}
int collinear(int i)
{
    return fabs((p[stack[i-1]].x-p[stack[i]].x)*(p[stack[i]].y-p[stack[i+1]].y)+(p[stack[i]].x-p[stack[i+1]].x)*(p[stack[i-1]].y-p[stack[i]].y))<1e-6;                           
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
            if(left(stack[top-3],stack[top-2],stack[top-1])) break;
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
            if(left(stack[top-3],stack[top-2],stack[top-1])) break;
            top--;
            stack[top-1]=stack[top];
         }
    }
    //top--;
    return top;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
       int n,i;
       scanf("%d",&n);
       for(i=0;i<n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
       int num=convex(n);
      // for(int i=0;i<num;i++)
      //     printf("(%d,%d)\n",p[stack[i]].x,p[stack[i]].y);
      stack[num++]=stack[1];
      stack[num++]=stack[2];
      stack[num++]=stack[3];
      stack[num++]=stack[4];
      for(i=2;i<num-3;i++)
         if(!(collinear(i-1)||collinear(i+1)))
         {
         printf("NO\n");
         break;
         }
    if(i>=num-2)
    {
    double A=0;
    for(i=0;i<num-1;i++)
        A+=(p[stack[i]].x*p[stack[i+1]].y-p[stack[i]].y*p[stack[i+1]].x);
    if(fabs(A)<1e-6) printf("NO\n");
    else printf("YES\n");
    }
    }
}
