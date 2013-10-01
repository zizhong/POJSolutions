#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Seg
{
       int l,r;
       void init()
       {
            scanf("%d%d",&l,&r);
            l++;
       }
}seg[10010];
bool cmp(const Seg &s1,const Seg &s2)
{
     return s1.l < s2.l;
}
int n,len;
int main()
{
    scanf("%d%d",&n,&len);
    for(int i=0;i<n;i++)
    {
        seg[i].init();
    }
    sort(seg,seg+n,cmp);
    int ans=0,p=0;
    for(int i=0;i<n;i++)
    {
          if(seg[i].r<p) continue;  
          if(seg[i].l>p) p=seg[i].l;
          int tmp=(seg[i].r-p+1+len-1)/len;
          ans+=tmp;
          p=seg[i].l-1+tmp*len+1;
    }
    printf("%d\n",ans);
    scanf("%'d");
}
