#include<stdio.h>
int main()
{
    double n,m;
    while(scanf("%lf%lf",&n,&m)&&int(n+m))
    {
        int i;
        double r=1.0;
        for(i=1;i<=n;i++)
        {
            if(i<=m)
               r/=(i*1.0);
            else
              r/=((i-m)*1.0);
            r*=i*1.0;
        }
        printf("%.0lf things taken %.0lf at a time is %.0lf exactly.\n",n,m,r);
    }
}
