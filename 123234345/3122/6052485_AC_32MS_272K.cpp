#include<stdio.h>
#include<math.h>
double ri[10005];
int judge(double m,int pie_n,int friend_n,double *p)
{
    int i,sum=0;
    for(i=1;i<=pie_n;i++)
    {
        double k=-1;
        sum+=int((p[i]*acos(k))/m);
    }
    if(sum>friend_n)
        return 1;
    else
        return 0;
}
double _abs(double ll)
{
    if(ll<0)
        return ll*(-1);
    else
        return ll;
}
int main()
{
    int t,pie_n,friend_n,i;
    scanf("%d",&t);
    while(t--)
    {
        double mm=0;
        scanf("%d%d",&pie_n,&friend_n);
        for(i=1;i<=pie_n;i++)
        {
            scanf("%lf",&ri[i]);
            ri[i]=ri[i]*ri[i];
            if(ri[i]>mm)
                mm=ri[i];
        }
       double min=0,max=mm*acos(-1.0),mid;
        while(_abs(max-min)>0.000005)
        {
            mid=(max+min)/2;
            if(judge(mid,pie_n,friend_n,ri))
           min=mid;
            else
                max=mid;
        }
        printf("%.4lf\n",mid);
    }
    return 0;
}
