#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20010;
struct Doll
{
       int w,h;
       void read(){scanf("%d%d",&w,&h);}
}d[N];
bool cmp(const Doll& a,const Doll& b)
{
     if(a.w!=b.w) return a.w<b.w;
     return a.h<b.h; 
}
int v[N];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n;
         scanf("%d",&n);
         for(int i=0;i<n;i++)
              d[i].read(),v[i]=0;
         sort(d,d+n,cmp);
         int ans=0,mi;
         for(int i=0;i<n;i++) if(!v[i])
         {
              ans++;
              mi=i;
              for(int j=i+1;j<n;j++)
              {
                   if(d[mi].w<d[j].w&&d[mi].h<d[j].h)
                         v[j]=1,mi=j;
              }
         }
         printf("%d\n",ans);
    }
}
