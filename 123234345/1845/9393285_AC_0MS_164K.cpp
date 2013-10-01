#include<cstdio>
#include<cstring>
const int mod=9901,N=7080;
bool isp[N];
int pl[N],plen;
void init_p()
{
     for(int i=2;i<N;i++) if(isp[i]==false)
     {
           pl[plen++]=i;
           for(int j=i+i;j<N;j+=i) isp[j]=true;
     }
}
int x,y;
int pow(int p,int k)
{
    if(k==0) return 0;
    if(k==1) return p%mod;
    int t=pow(p,k/2);
    t=t*t%mod;
    return k%2?t*p%mod:t;
}
int pow_sum(int p,int k)
{
    if(k==0) return 1;
    if(k==1) return (p+1)%mod;
    int t=pow_sum(p,(k-1)/2);
    if(k%2) return (t+pow(p,(k+1)/2)*t)%mod;
    return (t+pow(p,k/2)+pow(p,k/2+1)*t)%mod;
}
int solve()
{
    if(x==0) return 0;
    if(y==0) return 1;
    init_p();
    int ans=1;
    for(int i=0;i<plen && pl[i]*pl[i]<=x;i++) if(x%pl[i]==0)
    {
           int k=0;
           while(x%pl[i]==0) x/=pl[i],k++; 
           ans=ans*pow_sum(pl[i],k*y)%mod;
    }
    if(x>1) ans=ans*pow_sum(x,y)%mod;
    return ans;
}
int main()
{
    scanf("%d%d",&x,&y);
    printf("%d\n",solve());
    scanf("%'d");
}
