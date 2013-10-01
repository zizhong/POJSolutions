#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
struct Node
{
     int a,b;
     void init(){scanf("%d%d",&a,&b);}
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
         int p=0,flag=1;
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
