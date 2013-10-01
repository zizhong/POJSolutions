#include <stdio.h>
#include <math.h>
int main()
{
	long n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		long m=y-x,l=long(sqrt(m));
		if(m==0) printf("0\n");
		else if(m==l*l) printf("%d\n",2*l-1);
		else if(m<=l*l+l) printf("%d\n",2*l);
		else printf("%d\n",2*(l+1)-1);
	}
}