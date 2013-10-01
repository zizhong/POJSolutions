#include<stdio.h>
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}
int abs(int a)
{
    return (a<0)?-a:a; 
}
int main()
{
    int t;
    scanf("%d",&t);
    int h=t;
    while(t--)
    {
        int x=0,y=0,dx,dy,I=0,E=0,A=0,i,m;
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&dx,&dy);
            A+=x*(y+dy)-(x+dx)*y;
            E+=abs(gcd(dx,dy));
            x+=dx,y+=dy;         
        }
        I=(A+2-E)/2;
        double A1=0.5*A;
        printf("Scenario #%d:\n",h-t);
        printf("%d %d %.1f\n\n",I,E,A1);
    }
}
