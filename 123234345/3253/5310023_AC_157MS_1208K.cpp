#include<iostream>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<string>

using namespace std;

multiset<__int64> ms;
multiset<__int64>::iterator p1,p2;

int main()
{
		
	//cout<<sizeof(_int64)<<endl;
	int i,N,k;
	__int64 count,cou;
	cin>>N;
	for(i=0;i<N;i++)
	{
		cin>>k;
		ms.insert(k);
	}

	count=0;
	while(ms.size() > 1)
	{
		p1 = p2 = ms.begin();
		p2++;

		cou = *p1 + *p2;
		ms.erase(p1);
		ms.erase(p2);
		ms.insert(cou);
		count+=cou;
	}

	printf("%I64d\n",count);

return 1;}
