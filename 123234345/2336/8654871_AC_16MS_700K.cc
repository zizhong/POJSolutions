#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstdio>
#include <climits>
#include <queue>
using namespace std;

int data[1500];

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int c, time, m, tim = 0, times = 0;
		scanf("%d%d%d", &c, &time, &m);
		for (int i=0; i < m; i++)
			scanf("%d", data+i);
		if (m % c != 0)
		{
			int tmp = m % c;
			times = m / c + 1;
			tim = data[tmp-1] + time;
			if (tmp != m)
			{
				tim += time;
			for (int i=tmp+c-1; i < m; i+= c)
			{
				if (tim < data[i])
					tim = data[i];
				tim += 2*time;
			}
			tim -= time;
			}

		}
		else
		{
			times = m / c;
			for (int i=c-1; i < m; i+= c)
			{
				if (tim < data[i])
					tim = data[i];
				tim += 2*time;
			}
			tim -= time;
		}
		printf("%d %d\n", tim, times);



	}

	return 0;
}