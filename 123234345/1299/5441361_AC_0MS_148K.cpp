#include<stdio.h>
#include<math.h>
#define PI 3.14159
int main()
{
    char st[16];
    while(scanf("%s",st)&&st[0]!='E')
    {
        char end[8];
        double r,g,a;
        scanf("%lf%lf%lf%s",&r,&g,&a,end);
        if(a>180) a=360-a;
        double sNeed=a*r*PI/90,
               sCan=g*5;
        int re;
        if(sNeed<sCan||fabs(sNeed-sCan)<1e-6)
        {
             printf("YES ");
             re=int(g-sNeed*0.2);
        }
        else
        {
            printf("NO ");
            re=int(g*5);
        }
        printf("%d\n",re);
    }
}
