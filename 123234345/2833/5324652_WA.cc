#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
const int maxn = 100;
int big[maxn], small[maxn];
int n1, n2, n, l1, l2;

inline void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void Solve() {
	__int64 sum = 0;
	l1 = l2 = 0;
	int i, j, x;
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
		big[l1++] = x;
		j = l1 - 1;
		for (; j > 0 && big[j] > big[j - 1]; j--)
			Swap(big[j], big[j - 1]);
		small[l2++] = x;
		j = l2 - 1;
		for (; j > 0 && small[j] < small[j - 1]; j--)
			Swap(small[j], small[j - 1]);
		if (l1 > n1) l1--;
		if (l2 > n2) l2--;
	}
	for (i = 0; i < l1; i++)
		sum -= big[i];
	for (i = 0; i < l2; i++)
		sum -= small[i];
	long double ans = (long double)sum;
	ans /= (long double)(n - n1 - n2);
	cout << setiosflags(ios::fixed) << setprecision(6) << ans << endl;
}

int main() {
	while (1) {
		scanf("%d %d %d", &n1, &n2, &n);
		if (n1 == 0 && n2 == 0 && n == 0) break;
		Solve();
	}
	return 0;
}
