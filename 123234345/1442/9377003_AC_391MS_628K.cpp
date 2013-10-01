#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=30010;
int a[N];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
          priority_queue<int, deque<int>, less<int> > maxrq;
          priority_queue<int, deque<int>, greater<int> > minrq;
          for(int i=0;i<n;i++) scanf("%d",&a[i]);
          int nn=0;
          for(int j=1;j<=m;j++)
          {
               int x;
               scanf("%d",&x);
               for(;nn<x;nn++)
               {
                    minrq.push(a[nn]);
                    maxrq.push(minrq.top()), minrq.pop();
                    minrq.push(maxrq.top()), maxrq.pop();
               }
               maxrq.push(minrq.top()), minrq.pop();
               printf("%d\n",maxrq.top());
          }
    }
}
