#include <cstdio>
int i, j, n, k, s[100002], a;
int main()
{
	scanf("%d%d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		s[i] = s[i-1] + j;
	}
	for (i = 0, j = 0; i <= n-k; i++)
	{
		if ((i-j)*(s[i+k]-s[j]) - (i+k-j)*(s[i]-s[j]) > 0) j = i;
		a >?= 1000*(s[i+k]-s[j])/(i+k-j);
	}
	printf("%d\n", a);}
