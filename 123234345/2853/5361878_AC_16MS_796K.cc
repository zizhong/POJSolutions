#include <iostream>
using namespace std;
int main()
{
	int N;
	double x;
	int count=1,sum;
	int tempory;
	double a1;
	cin>>N;
	while(count<=N) 
	{	cin>>tempory>>x;
		sum=0;
		for(int n=2;;n++)
		{
			a1=(2.0*x/n-n+1)/2;
			if(a1>0&&a1==long(a1))  sum++;
			if(a1<=0) break;
		}
		cout<<count<<" "<<sum<<endl;
		count++;
	}
	return 0;
}
