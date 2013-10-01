#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
using namespace std;
typedef  long long ll;
bool f[100010];
int num[100010];
int A[128], C[128];
int main()
{
#ifdef _ZZZ_
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m;
  while (cin >> n >> m , n) {
    for(int i = 0; i < n; i ++) {
      cin >> A[i];
    }
    for(int i = 0; i < n; i ++) {
      cin >> C[i];
    }
    memset(f, false, sizeof(f));
    f[0] = true;
    for(int i = 0; i < n; i ++) {
      for(int j = 0; j <= m; j ++) {
        num[j] = 0;
      }
      for(int j = A[i]; j <= m; j ++) {
        if (!f[j] && f[j - A[i]] && num[j - A[i]] < C[i]) {
          f[j] = true;
          num[j] =  num[j - A[i]] + 1;
        }
      }
    }
    int ans = 0;
    for(int i = 1; i <= m; i ++) {
      ans += f[i];
    }
    cout << ans << endl;
  }
  return 0;
}
