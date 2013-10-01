#include<stdio.h>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int abs(int a)
{
    return a>0?a:-a;
}
int main()
{
    int x1,x2,x3,y1,y2,y3;
    while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)&&(x1+x2+x3+y1+y2+y3))
    {
        int A=0,E=0,I;
        A=abs(x1*y2-x2*y1+x2*y3-x3*y2+x3*y1-x1*y3);
        E=abs(gcd(x2-x1,y2-y1))+abs(gcd(x3-x2,y3-y2))+abs(gcd(x3-x1,y3-y1));
        I=(A+2-E)/2;
        printf("%d\n",I);
    }
}
