#include<cstdio>
#include<cstring>
const int N=1<<20,M=90000;
bool isp[N];
int pl[M],plen;
int n;
void init_p()
{
     isp[0]=isp[1]=true;
     for(int i=2;i<1<<20;i++) if(!isp[i])
     {
         pl[plen++]=i;
         for(int j=i+i;j<1<<20;j+=i) isp[j]=true;
     }
}
int cnt[M][2],pcnt;
void fact_n()
{
     memset(cnt,0,sizeof(cnt));
     pcnt=0;
     int x=n;
     for(int i=0;i<plen && (__int64)pl[i]*pl[i]<=x;i++)
     {
          cnt[pcnt][0]=pl[i];
          while(x%pl[i]==0) x/=pl[i],cnt[pcnt][1]++;
          pcnt++;            
     }
     if(x!=1) cnt[pcnt][0]=x,cnt[pcnt++][1]=1;
}
int fac[21],ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
void delp(int x)
{
     for(int i=2;i<=x;i++)
     {
          int tmp=i;
          for(int j=1;j<=ans;j++)
          {
              int d=gcd(tmp,fac[j]);
              tmp/=d;
              fac[j]/=d;
              if(tmp==1) break;
          }
     }
     //puts("----");for(int i=1;i<=ans;i++) printf("%d ",fac[i]);puts("");
}
void solve()
{
     ans=0;
     for(int i=0;i<pcnt;i++)
         ans+=cnt[i][1];
     printf("%d ",ans);
     for(int i=1;i<=ans;i++)
           fac[i]=i;
     for(int i=0;i<pcnt;i++)
           delp(cnt[i][1]);
     __int64 ans2=1;
     for(int i=1;i<=ans;i++)
         ans2*=fac[i];
     printf("%I64d\n",ans2);
}
int main()
{
    init_p();
    while(scanf("%d",&n)==1)
    {
          fact_n();
          solve();
    }
}
