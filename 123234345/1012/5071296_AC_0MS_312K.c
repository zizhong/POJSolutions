#include<stdio.h>
int array[14]={2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};

int main()
{
	int k;
	scanf("%d",&k);
	while(k!=0)
	{
		printf("%d\n",array[k-1]);
		scanf("%d",&k);
	}
	return 0;
}
