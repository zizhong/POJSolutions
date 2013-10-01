#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef  __int64 i64;
i64 max(i64 a,i64 b){return a>b?a:b;}
i64 k,m;
int digit[20],len;
int cntdig(i64 x)
{
    int t=0;
    while(x) t++,x/=10;
    return t;
}
i64 cntlittle(i64 pre,i64 n)
{
    //printf("<%I64d>:\n",pre);
    i64 ans=0;
    int prelen=cntdig(pre),lenn=cntdig(n);
    ans=1;
    for(int i=prelen;i<lenn-1;i++)
    {
          ans=ans*10+1;
          pre=pre*10;
    }
    //printf("%I64d %I64d\n",ans,pre);
    if(pre*10-1<=n) ans+=n-pre*10+1;
    //printf("%I64d ..\n",ans);
    return ans;
    
}
i64 dfs(int x,i64 pre,i64 n)
{
    if(x==-1) return len;
    i64 ans=0;
    for(int i=!pre;i<=digit[x];i++)
    {
         if(i==digit[x]) ans+=dfs(x-1,pre*10+i,n);
         else ans+=cntlittle(pre*10+i,n);
    }
    return ans;
}
i64 rank(i64 x,i64 n)
{
    len=0;
    i64 t=x;
    while(t)  digit[len++]=t%10,t/=10;
    return dfs(len-1,0,n);
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //printf("%I64d\n",rank(2,11));
    //printf("%I64d\n",rank(25,1831));
    while(scanf("%I64d%I64d",&k,&m)==2)
    {
          i64 l=max(k,m),r=1LL<<40;
          if(rank(m,l)==k) printf("%I64d\n",l);
          else if(rank(m,r)<k) printf("0\n");
          else
          {
              while(l+1<r)
              {
                    i64 mid=l+r>>1,tmp=rank(m,mid);
                    if(k<=tmp) r=mid;
                    else if(k>tmp) l=mid;
              }
              if(rank(m,r)==k) printf("%I64d\n",r);
              else puts("0");
          }
    }
}
