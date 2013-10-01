#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
	int a[123],b[123],i,flag;
	char c;
	int num;
	while(1)
	{
		flag=0;
		for(i=97;i<123;++i)
		{
			a[i]=0;
			b[i]=0;
		}
		++a[c];
		while(1)
		{
			c=getchar();
			if(c=='\n')
				break;

			if (c == EOF)
			{
				return 0;
			}

			++a[c];
		}
		while(1)
		{
			c=getchar();
			if(c=='\n')
				break;
			++b[c];
		}
		for(i=97;i<123;++i)
		{
			num=a[i]>b[i]?b[i]:a[i];
			while(num--)
			{
				printf("%c",i);
			}
		}
		printf("\n");
	}
}
