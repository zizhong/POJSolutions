#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=20010;
#define i64 __int64
struct Cow
{
       int v,d;
       void init(){scanf("%d%d",&v,&d);}
}cow[N];
int n;
bool cmp(const Cow& c1,const Cow &c2)
{
     return c1.v < c2.v;
}
i64 a[N],b[N];
int lowbit(int x){return x&(-x);}
void add(i64 *bit,int x,int d)
{
     while(x<=20000)
     {
          bit[x]+=d;
          x+=lowbit(x);
     }
}
i64 _sum(i64 *bit,int x)
{
    i64 ans=0;
    while(x>0)
    {
         ans+=bit[x];
         x-=lowbit(x);
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
          cow[i].init();
    sort(cow,cow+n,cmp);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    i64 ans=0,all=0;
    for(int i=0;i<n;i++)
    {
          i64 minsum=_sum(b,cow[i].d),minnum=_sum(a,cow[i].d);          
          ans+=cow[i].v * (minnum*cow[i].d - minsum) + cow[i].v*( (all - minsum) - (i-minnum)*cow[i].d);
          all+=cow[i].d;
          add(a,cow[i].d,1);
          add(b,cow[i].d,cow[i].d);
    }
    printf("%I64d\n",ans);
}
