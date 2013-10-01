#include<stdio.h>
int main()
{
    int a[10]={362880,40320,5040,720,120,24,6,2,1,1};
	int in;
	scanf("%d",&in);
	while(in>=0)
	{
		if(in==0) puts("NO");
		else 
		{
			for(int i=0;i<10;i++)
				if(in>=a[i])in-=a[i];
			if(in==0)puts("YES");
			else puts("NO");
		} 				
		scanf("%d",&in);
	}
	return 0;	
}
