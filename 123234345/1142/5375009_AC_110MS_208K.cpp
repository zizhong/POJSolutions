#include<iostream>
#include<cmath>
using namespace std;

int n;
int prime[1000];
void init()
{
	prime[0] = 2;
	int i , j , cur = 3;
	for ( i = 1 ; i < 1000 ; ++ i )
	{
		for ( j = 0 ; j < i ; ++ j )
		{
			if ( cur % prime[j] == 0 )
			{
				++ cur;
				j = -1;
			}
		}
		prime[i] = cur;
	}
			
}

bool isP(int n )
{
	if ( n <= prime[999] )
	{
		for ( int i = 0 ; i < 999 ; ++ i )
			if ( n == prime[i] )
				return true;
		return false;
	}
	else
	{
		for ( int i = 0 ; i < 1000 ; ++ i )
			if ( n % prime[i] == 0 )
				return false;
		return true;
	}
}
int bitsum(int n )
{
	int sum = 0;
	while ( n > 0 )
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}

bool isC(int n )
{
	int temp = bitsum(n) , sum = 0;

	for ( int i = 0 ; i < 1000 ; ++ i )
		while ( n % prime[i] == 0 )
		{
			sum += bitsum(prime[i]);
			n /= prime[i];
		}
		if ( isP(n) )
			sum += bitsum(n);
		else	//若不是素数，就把它的从prime[999]到sqrt(n)的所有质因数加起来
		{
			//算了吧
		}
		return ( sum == temp );
}
int main()
{
	init();
	while ( scanf("%d",&n) , n )
	{
		++ n ;
		while ( isP(n) || !isC(n))
		{
			++n;
		}
		cout << n << endl;
	}
	return 0;
}
