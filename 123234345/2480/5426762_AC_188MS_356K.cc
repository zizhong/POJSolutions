#include<stdio.h>
__int64 eular(__int64 n){
	__int64 ret=1,i;
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
    __int64 n;
    while(scanf("%I64d",&n)!=EOF)
    {
        __int64 sum=0;
        for(__int64 i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                sum+=eular(n/i)*i+eular(i)*(n/i);
                if(i*i==n) sum-=eular(n/i)*i;
            }
        }
        printf("%I64d\n",sum);
    }
}
