#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
double sz[10024];
int n, f;
bool ok(double x) {
  int tmp = 0;
  for(int i = 0; i < n; ++ i) {
    tmp += (int)(sz[i] / x + 1e-7);
  }
  return tmp >= f + 1;
}
int main()
{
#ifdef _ZZZ_
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int T;
  cin >> T;
  while(T --) {
    cin >> n >> f;
    double sum = 0;
    for(int i = 0; i < n; ++ i) {
      double r;
      cin >> r;
      sz[i] = pi * r * r;
      sum += sz[i];
    }
    double l = 0, r = sum / f + 1;
    while(r - l >= 1e-7) {
      double mid = (l + r) * 0.5;
      if (ok(mid)) l = mid;
      else r = mid;
    }
    printf("%.4f\n",r);
  }
  return 0;
}
