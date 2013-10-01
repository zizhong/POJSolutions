#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int NMAX=1002;
struct Point
{
       double x,y;
}p[NMAX];
int stack[NMAX];
int cmp(Point a,Point b)
{
    return a.y==b.y?a.x<b.x:a.y<b.y;
}
int left(int a,int b,int c)
{
    return (p[b].x-p[a].x)*(p[c].y-p[b].y)>(p[b].y-p[a].y)*(p[c].x-p[b].x);
}
int convex(int n)
{
    sort(p,p+n,cmp);
    int top=0,i;
    stack[top++]=0,stack[top++]=1;
    for(i=2;i<n;i++)
    {
        stack[top++]=i;
        while(top>=3)
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
    top--;
    return top;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,l,i;
    scanf("%d%d",&n,&l);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    int num=convex(n);
    double len=(num-2)*l*3.14159;
    for(i=0;i<num-1;i++)
        len+=sqrt((p[stack[i]].x-p[stack[i+1]].x)*(p[stack[i]].x-p[stack[i+1]].x)+
                   (p[stack[i]].y-p[stack[i+1]].y)*(p[stack[i]].y-p[stack[i+1]].y));
    len+=sqrt((p[stack[0]].x-p[stack[num-1]].x)*(p[stack[0]].x-p[stack[num-1]].x)+
                   (p[stack[0]].y-p[stack[num-1]].y)*(p[stack[0]].y-p[stack[num-1]].y));
    //len=len*12/8;
    printf("%.0f\n",len);
    /*for(i=0;i<num;i++)
        printf("(%.1f,%.1f)\n",p[stack[i]].x,p[stack[i]].y);*/
}
