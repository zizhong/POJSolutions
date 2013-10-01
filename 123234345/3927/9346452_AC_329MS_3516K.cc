#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 100015;

struct Node
{
    long long s, t, mid, half;   
    bool operator < (const Node &b) const
    {
        return mid < b.mid;
    }
};
Node arr[MAXN];
int n;
int main ()
{
    int i;
    double tmp;   
    while (scanf ("%d", &n), n)
    {
        for (i = 0; i < n; i++)
        {
            scanf ("%lld%lld", &arr[i].s, &arr[i].t);
            arr[i].mid = arr[i].t + arr[i].s;
            arr[i].half = (arr[i].t - arr[i].s) / 2 + 1;
        }
        sort (arr, arr + n);
        tmp = arr[0].s;
        for (i = 0; i < n; i++)
        {
            if (tmp + arr[i].half > arr[i].t)
                break;
            if (tmp + arr[i].half < arr[i+1].s)
                tmp = arr[i+1].s;
            else tmp += arr[i].half;
        }
        if (i >= n) printf ("YES\n");
        else printf("NO\n");
    }
}
