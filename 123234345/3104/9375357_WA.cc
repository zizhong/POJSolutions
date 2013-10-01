#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[100010];
bool cmp(const int a,const int b)
{
     return a>b;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
       scanf("%d",&d[i]);
    sort(d,d+n,cmp);   
    int k;
    scanf("%d",&k);
    __int64 ans=0,cc=0;
    for(int i=0;i<n;i++)
    {
         if(d[i]-cc<=0) break; 
         int tmp=(d[i]-cc+k-1)/k;
         ans+=tmp;
         cc+=tmp;
    }
    printf("%I64d\n",ans);
}
