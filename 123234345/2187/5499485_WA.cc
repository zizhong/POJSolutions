#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 50002
struct point
{
       int x,y;
}p[N];
int stack[N];
int cmp(point a,point b)
{
    return a.y==b.y?(a.x<b.x):(a.y<b.y);
}
int left(int a,int b,int c)
{
    return (p[a].x-p[b].x)*(p[b].y-p[c].y)>=(p[a].y-p[b].y)*(p[b].x-p[a].x);
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
            if(left(stack[top-1],stack[top-2],stack[top-3])) break;
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
            if(left(stack[top-1],stack[top-2],stack[top-3])) break;
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
    int n,i,j;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
           scanf("%d%d",&p[i].x,&p[i].y);
    }
    int num=convex(n);
    int ans=0;
    for(i=0;i<num;i++)
       for(j=0;j<num;j++)
       {
        if(ans<((p[stack[i]].x-p[stack[j]].x)*(p[stack[i]].x-p[stack[j]].x)+(p[stack[i]].y-p[stack[j]].y)*(p[stack[i]].y-p[stack[j]].y)))   
            ans=(p[stack[i]].x-p[stack[j]].x)*(p[stack[i]].x-p[stack[j]].x)+(p[stack[i]].y-p[stack[j]].y)*(p[stack[i]].y-p[stack[j]].y);     
       }
    printf("%d\n",ans);
}
