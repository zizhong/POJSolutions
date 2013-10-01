#include<iostream>
#include<cmath>
using namespace std;
#define SIZE 4194304
#define BUF 1500000
#define KEY(x) ((x) & (SIZE - 1))
int buf, ans;
typedef int llong;
int k[7], p[7], M, N;
struct Hash {
      int val, cnt, next;
}hash[SIZE + BUF];
bool flag[SIZE];
inline void init()
{
      memset(flag, false, sizeof(flag));
      buf = SIZE;
      ans = 0;
}
inline llong qpow(llong a, llong b)
{


      llong ret = 1;
      for(; b; b >>= 1) {
           if(b & 0x1)  ret *= a;
           a *= a;
      }
      return ret;
}
void in(int val)
{
      int key = KEY(val);
      if(key < 0) key *= -1;
      key = KEY(key);
      if(! flag[key]) {
            hash[key].val = val;
            hash[key].next = -1;
            hash[key].cnt = 1;
            flag[key] = true;
            return;
      }
      while(key != -1) {
           if(hash[key].val == val)  {
                hash[key].cnt ++;
                return;
           }
           if(hash[key].next == -1) break;
           key = hash[key].next;
      }
      hash[key].next = ++ buf;
      hash[buf].val = val;
      hash[buf].cnt = 1;
      hash[buf].next = -1;
}
void inhash(int val)
{
      int key = KEY(val);
      if(key < 0) key *= -1;
      key = KEY(key);
      if(! flag[key]) return ;
      while(key != -1) {
           if(hash[key].val == val)  {
                ans += hash[key].cnt;
                return ;
           }
           if(hash[key].next == -1) break;
           key = hash[key].next;
     }
}
void dfs(llong val,int depth)
{
      int i;
      if(depth == N / 2) {
           in(val);
           return;
      }
      for(i = 1; i <= M; i ++) 
           dfs(val + k[depth] * qpow(i, p[depth]), depth + 1);
}
void Dfs(llong val,int depth)
{
      int i;
      if(depth == N) {
           inhash(- val);
           return;
      }
      for(i = 1; i <= M; i ++) 
           Dfs(val + k[depth] * qpow(i, p[depth]), depth + 1);
}
int main()
{
      int i;
      while(scanf("%d %d", &N, &M) != EOF) {
           init();
           for(i = 0; i < N; i ++) scanf("%d %d", &k[i], &p[i]);
           dfs(0, 0);
           Dfs(0, N / 2);
           printf("%d\n", ans);
      }}

