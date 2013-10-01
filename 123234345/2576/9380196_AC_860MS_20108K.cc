#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 105
#define maxm 450
#define inf 0x3f3f3f3f
int n;
int v[maxn];
int f[maxn][maxn * maxm];
int sum;

int main()
{
    scanf("%d", &n);
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    memset(f, 0, sizeof(f));
    f[0][0] = true;
    for (int k = 0; k < n; k++)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            for (int j = 0; j + v[k] <= sum; j++)
                if (f[i][j])
                    f[i + 1][j + v[k]] = true;
    }
    int ans = inf;
    for (int i = sum; i >= 0; i--)
        if (f[n / 2][i])
        {
            if (abs(sum - i - i) < abs(sum - ans - ans))
                ans = i;
        }
    int x = sum - ans;
    if (x > ans) swap(x, ans);
    printf("%d %d\n", x, ans);
}

