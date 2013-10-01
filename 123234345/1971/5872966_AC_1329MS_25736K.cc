#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 1001;
const int MAXM = 20000;
const int PRIME = 19997;
struct Node {
     int x, y;
}node[MAXN];
struct Point {
     int midx, midy, cnt;
};
vector <Point> hash[MAXM];
int resCnt;
void Hash(int sum, Point pt) {
     sum %= PRIME;
     vector<Point>::size_type ix, size = hash[sum].size();
     for(ix = 0; ix < size; ix ++) {
           int midx = hash[sum][ix].midx;
           int midy = hash[sum][ix].midy;
           if(midx == pt.midx && midy == pt.midy) {
                resCnt += hash[sum][ix].cnt;
                hash[sum][ix].cnt += pt.cnt;
                break;
           }
     }
     if(ix == size) hash[sum].push_back(pt);
}
int main() {
     int cas;
     scanf("%d", &cas);
     while(cas --) {
           int i, j, n;
           scanf("%d", &n);
           for(i = 0; i < n; i ++) {
                scanf("%d %d", &node[i].x, &node[i].y);
           }
           for(i = 0; i < PRIME; i ++) hash[i].clear();
           Point pt;
           resCnt = 0;
           for(i = 0; i < n; i ++) {
                for(j = i + 1; j < n; j ++) {
                     pt.midx = node[i].x + node[j].x;                     pt.midy = node[i].y + node[j].y;
                     pt.cnt = 1;
                     int sum = pt.midx + pt.midy;
                     if(sum < 0) sum *= -1;
                     Hash(sum, pt);
                }
           }
           printf("%d\n", resCnt);
     }}

