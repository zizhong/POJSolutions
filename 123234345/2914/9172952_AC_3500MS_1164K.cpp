#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 505
#define inf 1000000000
int n, m;
int g[N][N];
int dist[N], node[N];
bool used[N];
inline int min(int a, int b)
{
 return (a<b)?a:b;
}
int mincut()
{
 int i, j, k, pre, maxj, ans = inf;
 for(i = 0; i < n; i++)
  node[i] = i;    //保存顶点 ，固定顶点为0
 while(n > 1)
 {
  memset(used,0,sizeof(used));
  maxj = 1;
  used[node[0]] = 1;
  for(i = 1; i < n; i++)
  {
   dist[node[i]] = g[node[0]][node[i]]; //初始化距离数组dist[]
   if(dist[node[i]] > dist[node[maxj]])   //寻找最大距离——求最大生成树
    maxj = i;
  }
  pre = 0;
  //求最大生成树，并进行最小割操作。
  for(i = 1; i < n; i++)
  {
   if(i == n-1)
   {
    //只剩最后一个没加入集合的点，更新最小割
    ans = min(ans,dist[node[maxj]]);
    for(k = 0; k < n; k++) //合并最后一个点以及推出它的集合中的点
     g[node[k]][node[pre]] = g[node[pre]][node[k]] += g[node[k]][node[maxj]];
    node[maxj] = node[--n];//缩点后的图
   }
   used[node[maxj]] = 1;
   pre = maxj;
   maxj = -1;
   for(j = 1; j < n; j++)
    if(!used[node[j]])
    {
     //将上次求的maxj加入集合，合并与它相邻的边到割集
     dist[node[j]] += g[node[pre]][node[j]];//dist[]保存的是一个积累量。
     if(maxj == -1 || dist[node[maxj]] < dist[node[j]])
      maxj = j;
    }
  }
 }
 return ans;
}
int main()
{
 while(scanf("%d %d",&n,&m) != -1)
 {
  memset(g,0,sizeof(g));
  while(m--)
  {
   int a, b, c;
   scanf("%d %d %d",&a,&b,&c);
   g[a][b] += c;
   g[b][a] += c;
  }
  printf("%d\n",mincut());
 }
 return 0;
}
