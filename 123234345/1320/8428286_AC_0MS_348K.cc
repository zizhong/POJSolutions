#include<stdio.h>
#include<math.h>
void pell(int n)
{
    long long p0=0,p1=1,q0=1,q1=0,p2,q2,a0=(int)sqrt(n*1.0),a1=a0,a2,h1=1,g1=0;
    int cnt=0;
    while(true)
    {
        g1=-g1+a1*h1;
        h1=(n-g1*g1)/h1;
        a2=(g1+a0)/h1;
        p2=a1*p1+p0;
        q2=a1*q1+q0;
        if(p2*p2 - n*q2*q2 == 1)
        {
            cnt++;
            if(cnt>1&&cnt<12) printf("%10lld%10lld\n",q2,(p2-1)/2);
            if(cnt==12) return ;
        }
        p0=p1,p1=p2;
        q0=q1,q1=q2;
        a1=a2;
    }
}
int main()
{
    pell(8);
    //scanf("%'d");
}
