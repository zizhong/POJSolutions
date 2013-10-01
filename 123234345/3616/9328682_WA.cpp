#include<cstdio>
#include<cstring>
#include<iostream>
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
int n,m,x;
int f[N];
int main()
{
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0;i<m;i++) 
    {
         p[i].init(x);
         f[i]=p[i].p;
    }
    for(int i=0;i<m;i++)
    {
         for(int j=0;j<m;j++) if(i!=j && p[j].r<p[i].l)
         {
              f[i]=max(f[i],f[j]+p[i].p);
         }
    }
    int ans=0;
    for(int i=0;i<m;i++) if(ans<f[i])
        ans=f[i];
    printf("%d\n",ans);
    //scanf("%'d");
}
