#include <stdio.h>
int main()
{
	__int64 a,i;
	scanf("%I64d",&a);
	for(i=a;;i--)if((a*a+1)%i==0)break;
	printf("%I64d\n",2*a+(a*a+1)/i+i);
}

