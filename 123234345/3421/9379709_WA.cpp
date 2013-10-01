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
     for(int i=0;i<plen && pl[i]<=x*1.0/pl[i];i++)
     {
          cnt[pcnt][0]=pl[i];
          while(x%pl[i]==0) x/=pl[i],cnt[pcnt][1]++;
          pcnt++;            
     }
     if(x!=1) cnt[pcnt][0]=x,cnt[pcnt++][1]=1;
}
int fac[21],ans;
void delp(int x)
{
     for(int i=2;i<=x;i++)
     {
          for(int j=1;j<=ans;j++)
              if(fac[j]%i==0) {fac[j]/=i;break;}
     }
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
     int ans2=1;
     for(int i=1;i<=ans;i++)
         ans2*=fac[i];
     printf("%d\n",ans2);
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
