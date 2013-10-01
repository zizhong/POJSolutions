#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int st[100][1024],top[1024];
const int mod=100003;
int q[100010],head,tail;
int main()
{
    int n,K,P;
    scanf("%d%d%d",&n,&K,&P);
    int head=0,tail=0;
    for(int i=1;i<=K;i++)
        q[tail++]=i;
    int p=1;
    for(int k=0;k<K;k++)
    {
          st[p][top[p]++]=q[head++];
          if(head==mod) head=0;
          ++p;
          if(p==n) p=0;
          for(int i=0;i<P;i++)
          {
               q[tail++]=q[head++];
               if(tail==mod) tail=0;
               if(head==mod) head=mod;
          }
    }
    sort(st[0],st[0]+top[0]);
    for(int i=0;i<top[0];i++)
        printf("%d\n",st[0][i]);
    //scanf("%'d");
}
