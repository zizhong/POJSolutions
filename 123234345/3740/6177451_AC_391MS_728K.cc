#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int MAXN = 17;
const int MAXM = 301;
int matrix[MAXN][MAXM];
int link[MAXN][MAXN];
int rowCnt[MAXN];
int m, n;
struct node_T {
     int row[MAXN];
     int rCnt;
     int cnt;
     bool operator < (const node_T &nod) const {
          return cnt < nod.cnt;
     }
};
bool bfs() {
     priority_queue<node_T> Q;
     node_T cur, tmp;
     int i, j;
     for(i = 0; i < m; i ++) {
          cur.row[0] = i;
          cur.rCnt = 1;
          cur.cnt = rowCnt[i];
          Q.push(cur);
     }
     while(! Q.empty()) {
          cur = Q.top();
          Q.pop();
          if(cur.cnt == n) return true;
          tmp = cur;
          for(i = cur.row[cur.rCnt - 1] + 1; i < m; i ++) {
              for(j = 0; j < cur.rCnt; j ++) {
                  if(! link[i][cur.row[j]]) break;
              }
              if(j == cur.rCnt) {
                  tmp.rCnt = cur.rCnt + 1;
                  tmp.row[tmp.rCnt - 1] = i;
                  tmp.cnt = cur.cnt + rowCnt[i];
                  Q.push(tmp);
              }
          }
     }
     return false;
}
int main() {
     int i, j, k;
     while(scanf("%d%d", &m, &n) != EOF) {
          memset(rowCnt, 0, sizeof(rowCnt));
          for(i = 0; i < m; i ++) {
              for(j = 0; j < n; j ++) {
                   scanf("%d", &matrix[i][j]);
                   rowCnt[i] += matrix[i][j];
              }
          }
          for(i = 0; i < m; i ++) {
              link[i][i] = 0;
              for(j = i + 1; j < m; j ++) {
                   for(k = 0; k < n; k ++) {
                        if(matrix[i][k] & matrix[j][k]) break;
                   }
                   if(k < n) {
                        link[i][j] = link[j][i] = 0;
                   }else {
                        link[i][j] = link[j][i] = 1;
                   }
              }
          }
          if(bfs()) printf("Yes, I found it\n");
          else printf("It is impossible\n");
     }}
