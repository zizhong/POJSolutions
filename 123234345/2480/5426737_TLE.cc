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
    while(scanf("%d",&n)!=EOF)
    {
        int sum=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum+=eular(n/i)*i+eular(i)*(n/i);
                if(i*i==n) sum-=eular(n/i)*i;
            }
        }
        printf("%d\n",sum);
    }
}
