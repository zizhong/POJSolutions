#include <stdio.h>
#define SIZE 101
int N;
int A[SIZE], B[SIZE];
int abs(int x)
{
	return (x > 0) ? x : -x;
}
int mid(int a, int b, int c)
{
	int t;
	if (a > b)
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b > c)
	{
		t = c;
		c = b;
		b = t;
	}
	return b;
}
int main()
{
	int i, ans;
	while (scanf("%d", &N) != -1 && N > 0)
	{
		ans = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
		}
		if (N == 1)
		{
			printf("0\n");
			continue;
		}
		B[1] = A[1];
		for (i = 2; i < N; i++)
		{
			B[i] = mid(A[i], B[i - 1], A[i + 1]);
			ans += abs(A[i] - B[i]);
			ans += abs(B[i] - B[i - 1]);
		}
		ans += abs(A[N] - B[N - 1]);
		B[N] = B[N - 1];
		printf("%d\n", ans);
	}
}