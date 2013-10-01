#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1024;
struct Node
{
       int l,r,p;
       void init(int x)
       {
            scanf("%d%d%d",&l,&r,&p);
            r+=x;
       }
}p[N];
bool cmp(const Node &p1,const Node &p2)
{
     return p1.r <= p2.r;
}
int n,m,x;
int f[N];
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<m;i++) 
         p[i].init(x);
    sort(p,p+m,cmp);
    for(int i=0;i<m;i++)
    {
         f[i]=p[i].p;
         for(int j=0;j<m;j++) if(p[j].r<=p[i].l)
         {
              f[i]=max(f[i],f[j]+p[i].p);
         }
    }
    int ans=0;
    for(int i=0;i<m;i++) if(ans<f[i])
        ans=f[i];
    printf("%d\n",ans);
    scanf("%'d");
}
