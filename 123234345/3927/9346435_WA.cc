#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define i64 __int64
const int N=100010;
struct Node
{
     i64 a,b;
     void init(){scanf("%I64d%I64d",&a,&b);}
}wed[N];
bool cmp(const Node& n1,const Node &n2)
{
     return n1.b==n2.b?n1.a<n2.a:n1.b<n2.b;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=0;i<n;i++)
             wed[i].init();
         sort(wed,wed+n,cmp);
         int flag=1;
         i64 p=0;
         for(int i=0;i<n;i++)
         {                 
               if(wed[i].a>p) p=wed[i].a;
               p+=(wed[i].b-wed[i].a+1)/2;
               if(wed[i].b<p) {flag=0;break;}
               p++;
         }
         puts(flag?"YES":"NO");
    }
}
