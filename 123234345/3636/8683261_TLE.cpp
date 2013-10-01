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
     return a.h>b.h; 
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n;
         scanf("%d",&n);
         for(int i=0;i<n;i++)
              d[i].read();
         sort(d,d+n,cmp);
         //for(int i=0;i<n;i++)
          //    d[i].disp();
         int v[N]={0},ans=0,mi;
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
