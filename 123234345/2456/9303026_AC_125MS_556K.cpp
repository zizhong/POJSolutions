#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010;
int p[N];
int n,c;
bool ok(int x)
{
    int pre=0,num=1;
    for(int i=2;i<n;i++)
        if(p[i]-p[pre]>=x)
               num++,pre=i;
    //printf("%d %d\n",x,num);
    return num>=c;
}
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
          scanf("%d",&p[i]);
    sort(p,p+n);
    int l=0,r=0x3fffffff;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(ok(mid)) l=mid;
        else r=mid;
    }
    printf("%d\n",l);
}
