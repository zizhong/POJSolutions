#include<cstdio>
#include<cstring>
#define i64 __int64
const int N=100010;
i64 b1[N],b2[N];
i64 a[N];
int lowbit(int x){return x&(-x);}
void add(i64 *b,int x,int d)
{
     for(;x<N;x+=lowbit(x))
            b[x]+=d;
}
i64 _sum(i64 *b,int x)
{
    i64 ans=0;
    while(x>0)
    {
         ans+=b[x];
         x-=lowbit(x);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         scanf("%d",&n);
         memset(b1,0,sizeof(b1));
         memset(b2,0,sizeof(b2));
         for(int i=1;i<=n;i++)
         {
              scanf("%I64d",&a[i]);
              add(b1,a[i],1);
         }
         i64 ans=0;
         for(int i=1;i<=n;i++)
         {              
              add(b1,a[i],-1);
              if(i>1 && i<n)
              {
                   i64 left_little=_sum(b2,a[i]),
                       right_little=_sum(b1,a[i]);
                   i64 left_large = i-1-left_little,
                       right_large=n-i-right_little;
                   ans+=left_little * right_large + left_large * right_little;
                   
              }
              add(b2,a[i],1);
         }
         printf("%I64d\n",ans);
    }
}
