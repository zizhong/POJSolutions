#include <iostream>
using namespace std;
int a[1001], request[10000][2], n, p;
bool flag[1001];
void circle ( int start )
{
	int i;	
	for ( i = 1; i <= n; i ++ )
	{		if ( start <= n )
			a[i] = start;
		else
			a[i] = start % n;
		start++;
	}
}

int caculate ()
{
	int count = 0;
	for ( int i = 1; i <= n; i ++ )
		if ( flag[i] )
			count++;
	return count;
}

int main ()
{
	int i, j, s, t, count = 1000, k;
	scanf ( "%d%d", &n, &p );
	for ( j = 0; j < p; j ++ )
		scanf ( "%d%d", &request[j][0], &request[j][1] );

	for ( i  = 1; i <= n; i ++ )
	{
		circle ( i );
		memset ( flag, false, sizeof ( flag ) );

		for ( j = 0; j < p; j ++ )
		{
			int v1 = a[request[j][0]], v2 = a[request[j][1]];

			if ( v1 > v2 )
			{
				int temp = v1;
				v1 = v2;
				v2 = temp;
			}

			for ( k = v1; k < v2; k ++ )
				flag[k] = true;
		}

		count = count > caculate () ? caculate () : count;
	}

	printf ( "%d", count );}

