#include<cstdio>
#include<cstring>
long long l[40],r[40],w[40];
int ans[40];
long long n;
void solve()
{
     long long tmp=1;
     l[0]=0,r[0]=1,w[0]=0;
     for(int i=1;i<40;i++)
     {
          tmp<<=1;
          w[i]=tmp*(i%2?-1:1);
          l[i]=l[i-1],r[i]=r[i-1];
          if(i&1) l[i]-=tmp;
          else r[i]+=tmp;
     }
     int nn=-1;
     for(int i=39;i>=1;i--)
     {
            if(l[i]<=n && n<=r[i] && !(l[i-1]<=n && n<=r[i-1]))
            {
                  ans[i]=1;
                  n-=w[i];
                  if(nn==-1) nn=i;
            }
     }
     ans[0]=n;
     for(int i=nn;i>=0;i--) putchar('0'+ans[i]);puts("");
}
int main()
{
    scanf("%I64d",&n);
    if(n==0||n==1) {printf("%d\n",n);return 0;}
    solve();
    //scanf("%'d");
}
