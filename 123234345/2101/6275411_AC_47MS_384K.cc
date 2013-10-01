#include<stdio.h>
#include<math.h>
int main()
{
    int n,e;
    scanf("%d%d",&n,&e);
    double a=0,b=0,t;
    for(int i=1;i<n;i++)
    {
         scanf("%lf",&t);
         a+=t;
    }
    for(int i=1;i<e;i++)
    {
         scanf("%lf",&t);
         b+=t;
    }
    printf("%.0f\n",ceil(sqrt((a*a+b*b))));
}
