#include<cstdio>
#include<algorithm>
using namespace std;
const int N=20010;
struct Doll
{
       int w,h;
       void read(){scanf("%d%d",&w,&h);}
       void disp(){printf("<%d %d>\n",w,h);}
}d[N];
bool cmp(const Doll& a,const Doll& b)
{
     if(a.w!=b.w) return a.w<b.w;
     return a.h<b.h; 
}
bool v[N];
int main()
{
    int T;
    for(scanf("%d",&T);--T;)
    {
         int n;
         scanf("%d",&n);
         for(int i=0;i<n;i++)
              d[i].read(),v[i]=false;
         sort(d,d+n,cmp);
         int ans=0;
         Doll mn;
         for(int i=0;i<n;i++) if(!v[i])
         {
              ans++;
              mn=d[i];
              for(int j=i+1;j<n;++j)
              {
                   if(mn.w<d[j].w&&mn.h<d[j].h)
                         v[j]=true,mn=d[j];
              }
         }
         printf("%d\n",ans);
    }
}
