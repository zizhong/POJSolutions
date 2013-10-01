#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int n;
	int i2_mul;
	int i3_mul;
	int i5_mul;
	long ugly[1501];

	i2_mul = 1;
	i3_mul = 1;
	i5_mul = 1;
	ugly[1]=1;

	for(  int i = 2; i <= 1500; i++ )
	{
		ugly[i] = min(ugly[i2_mul]*2,min(ugly[i3_mul]*3,ugly[i5_mul]*5));

		if(ugly[i] == ugly[i2_mul]*2 )
			i2_mul++;
		if(ugly[i] == ugly[i3_mul]*3 )
			i3_mul++;
		if(ugly[i] == ugly[i5_mul]*5)
			i5_mul++;
	
	}


	while(true)
	{
		scanf("%d",&n);

		if( n == 0 )
			break;

		printf("%d\n",ugly[n]);

	}

	return 0;
}
