#include<stdio.h>
#include<stdlib.h>
const int N=100001;
struct Node
{
      int v,t;
}q[N];
int cmp(const void *a,const void *b)
{
    Node *p1=(Node *)a,
         *p2=(Node *)b;
    return -((__int64)p1->v)*p2->t+((__int64)p2->v)*p1->t;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d%d",&q[i].t,&q[i].v);
    }
    qsort(q,n,sizeof(q[0]),cmp);
    __int64 ans=0,tt=0;
    for(int i=0;i<n;i++)
    {
         ans+=q[i].v*tt;
         tt+=2*q[i].t;
    }
    printf("%I64d\n",ans);
}
