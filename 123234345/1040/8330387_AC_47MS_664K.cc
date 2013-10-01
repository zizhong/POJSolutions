#include <iostream>
#include <string>
#include <algorithm>
#include<stdio.h>
#include<string.h>
using namespace std; 
const int N = 23;
int n, m, k;
int ans;
int mark[8];
struct Station
{
       int st;
       int ed;
       int num;
}station[N];
bool cmp(Station a, Station b)
{
       if (a.st != b.st) return a.st < b.st;
       return a.ed < b.ed;
} 

void dfs(int pos, int curN, int earn, int left)
{
       if (pos >= k)
       {
              ans = max(earn, ans);
              return;
       }
       if (left + earn < ans) return;
       if (pos > 0)
              for (int i = station[pos - 1].st + 1; i <= station[pos].st; i++) curN += mark[i];
       left -= station[pos].num * (station[pos].ed - station[pos].st);
       if (curN >= station[pos].num)
       {
              mark[station[pos].ed] += station[pos].num;
              dfs(pos + 1, curN - station[pos].num, earn + station[pos].num * (station[pos].ed - station[pos].st), left);
              mark[station[pos].ed] -= station[pos].num;
       }
       dfs(pos + 1, curN, earn, left);
}
int main ()
{
       int i, sum;
       while (scanf("%d%d%d", &n, &m, &k) != EOF && (n | m | k))
       {
              sum = 0;
              for (i = 0; i < k; i++)
              {
                     scanf("%d%d%d", &station[i].st, &station[i].ed, &station[i].num);
                     sum += station[i].num * (station[i].ed - station[i].st);
              }
              memset(mark, 0, sizeof(mark));
              sort(station, station + k, cmp);
              ans = 0;
              dfs(0, n, 0, sum);
              printf("%d\n", ans);

       }

}