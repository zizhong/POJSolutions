#include <stdio.h>

char flag[100001];
int p[100001];

int Find(int x)
{
    if (p[x] < 0) return x;
    int t = p[x];
    p[x] = Find(t);
    flag[x] ^= flag[t];
    return p[x];
}

int main()
{
    char op;
    int cases, m, n, x, y;
    for (scanf("%d", &cases); cases; --cases)
    {
        scanf("%d%d", &n, &m);
        for (int i = n; i; --i)
            p[i] = -1, flag[i] = 0;
        for (; m; --m)
        {
            scanf("%*c%c%d%d", &op, &x, &y);
            if (op == 'A')
            {
                if (Find(x) == -1 || Find(x) != Find(y)) puts("Not sure yet.");
                else puts(flag[x] == flag[y] ? "In the same gang." : "In different gangs.");
            }
            else
            {
                int a = Find(x), b = Find(y);
                if (a == b) continue;
                if (p[a] < p[b])
                {
                    p[a] += p[b];
                    p[b] = a;
                    flag[b] = flag[x]^flag[y]^1;
                }
                else
                {
                    p[b] += p[a];
                    p[a] = b;
                    flag[a] = flag[x]^flag[y]^1;
                }
            }
        }
    }
} 
