#include <stdio.h>
void main()
{
	int a,i;
	scanf("%d",&a);
	for(i=a;;i--)if((a*a+1)%i==0)break;
	printf("%d\n",2*a+(a*a+1)/i+i);
}

