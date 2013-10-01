#include<iostream>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n==0&&k==0)
			break;
		int i=0;
		if(k>n/2)
			k=n-k;
		int j=k;
		__int64 sum=1;
		__int64 s=1;
		while(i<k)
		{
			sum*=n;
			n--;
			i++;
			if(sum%j==0)
				sum=sum/j;
			else
				s*=j;
			j--;
		}
		sum/=s;
	    printf("%I64d\n",sum); 
	}
	return 0;
}
