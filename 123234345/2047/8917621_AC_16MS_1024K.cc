#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, top;
int f[400][400];
struct node
{
    int beg, end, cost;
    bool operator<(const node & x)const
    {
        return end < x.end;
    }
} a[1100];
int main()
{
    while (~scanf("%d", &N) && N)
    {
        memset(f, 0, sizeof (f));
        for (int i = 1; i <= N; ++i)
            scanf("%d%d%d", &a[i].beg, &a[i].end, &a[i].cost);
        sort(a + 1, a + N + 1);
        for (int i = 1; i <= N; ++i)
        {
            for (int j = a[i - 1].end + 1; j <= a[i].end; ++j)
                for (int k = 0; k <= a[i].end; ++k)
                {
                    f[j][k] = f[j - 1][k];
                    f[k][j] = f[k][j - 1];
                }
            for (int j = a[i].end; j >= 0; --j)
            {
                f[a[i].end][j] = max(f[a[i].end][j], f[a[i].beg - 1][j] + a[i].cost);
                f[j][a[i].end] = max(f[j][a[i].end], f[j][a[i].beg - 1] + a[i].cost);
            }
        }
        printf("%d\n", f[a[N].end][a[N].end]);
    }
    return 0;
}
