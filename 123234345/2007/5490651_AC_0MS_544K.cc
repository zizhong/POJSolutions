#include<stdio.h>
#include<algorithm>
using namespace std;
struct Point{int x,y;}P[51];
int Stack[51];
int left(int a,int b,int c)
{
    return (P[b].x-P[a].x)*(P[c].y-P[b].y)>(P[b].y-P[a].y)*(P[c].x-P[b].x);
}
int cmp(const Point a,const Point b)
{
    return a.y==b.y?(a.x<b.x):(a.y<b.y);
}
int convex(int n)
{
    sort(P,P+n,cmp);
    int top=0,i;
    Stack[top++]=0;Stack[top++]=1;
    for(i=2;i<n;i++)
    {
        Stack[top++]=i;
        while(top>2)
        {
            if(left(Stack[top-3],Stack[top-2],Stack[top-1])) break;
            top--;
            Stack[top-1]=Stack[top];
        }
    }
    int top1=top;
    Stack[top++]=n-2;
    for(i=n-3;i>=0;i--)
    {
        Stack[top++]=i;
        while(top>=top1+2)
        {
            if(left(Stack[top-3],Stack[top-2],Stack[top-1])) break;
            top--;
            Stack[top-1]=Stack[top];
        }
    }
    return --top;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int x,y,i=0;
    for(i=0;scanf("%d%d",&P[i].x,&P[i].y)!=EOF;i++);
    int n=i;
    int num=convex(n);
    i=0;
    while(P[Stack[i]].x!=0) i++;
    printf("(0,0)\n");
    i++;
    for(;P[Stack[i%num]].x;i++)
       printf("(%d,%d)\n",P[Stack[i%num]].x,P[Stack[i%num]].y);
}
