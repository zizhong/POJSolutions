#include<stdio.h>
#include<cmath>
const double pi=acos(-1.0);
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
           int n,m;
           double t,c,a1,a2,a3,a4,a;    
           scanf("%d%d%lf%lf",&n,&m,&t,&c);
           a=n*m*t*t;
           a1=(t-c)*(t-c)*(n-2)*(m-2)+(2*t-c)*(t-c)*(n-2+m-2)+(2*t-c)*(2*t-c);
           a4=(m-1)*(n-1)*pi*(c/2)*(c/2);
           a3=(m-1)*(n-1)*(c*c-pi*c*c/4);
           a2=c*(t-c)*((m-2)*(n-1)+(m-1)*(n-2))+2*c*(t-c/2)*(n-1+m-1);
           printf("Case %d:\n",i);
           printf("Probability of covering 1 tile  = %.4lf%%\nProbability of covering 2 tiles = %.4lf%%\nProbability of covering 3 tiles = %.4lf%%\nProbability of covering 4 tiles = %.4lf%%\n"
                               ,100*a1/a,100*a2/a,100*a3/a,100*a4/a);
           if(i!=T) puts("");
    }
}
