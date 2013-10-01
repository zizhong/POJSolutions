#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int arr[1005], n;
int main ()
{
    int i, num, flag, T, ans;
    scanf ("%d", &T);
    while (T--)
    {
          scanf ("%d", &n);
          arr[0] = 0;
          for (i = 1; i <= n;i++)
          scanf ("%d", &arr[i]);
          sort (arr + 1, arr + n + 1);
          ans = 0;
          for (i = n; i >= 1; i -= 2)
                ans ^= arr[i] - arr[i-1] - 1;
          if (!ans) printf ("Bob will win\n");
          else printf ("Georgia will win\n");
   }
}