#include<stdio.h>
main()
{int n;
	while(scanf("%d",&n)&&n)
	{if(n%2==0) printf("No Solution!\n");
		else printf("%d\n",n-1);
	}
}

