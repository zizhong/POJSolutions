#include<stdio.h>
#include<string.h>
int p,q,r,s;
double solve()
{
	double ret=1,i;
	for(i=1;i<=q;i++)ret*=(p-q+i)/i;
	for(i=1;i<=s;i++)ret*=i/(r-s+i);
	return ret;
}
int main()
{
    while(scanf("%d%d%d%d",&p,&q,&r,&s)==4)
    {
        printf("%.5f\n",solve());
    }
}
