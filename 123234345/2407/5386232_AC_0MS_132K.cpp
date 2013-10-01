#include<stdio.h>
int eular(int n){
	int ret=1,i;
	for (i=2;i*i<=n;i++)
		if (n%i==0){
			n/=i,ret*=i-1;
			while (n%i==0)
				n/=i,ret*=i;
		}
	if (n>1)
		ret*=n-1;
	return ret;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        printf("%d\n",eular(n));
    }
}
