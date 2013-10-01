#include <stdio.h>
int main()
{
	long k;
	while(scanf("%ld",&k)!=EOF)
	{
	long j=1;
	long i=1,n=1;
	while (j<k)
	{
		j=j*10+1;
		++n;
	}
	while(j%k!=0)
	{
		j=j%k*10+1;
		++n;
	}
	printf("%d\n",n);
	}
}
