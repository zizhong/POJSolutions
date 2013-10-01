#include<stdio.h>
#define N 40000
bool ss[N+10]={1,1};
int pl[N>>1],plen;
int p,n,ans;
int fac[31][2],flen;
int hpow(int a,int b,int c)
{
int ret=1%c;
a%=c;
while(b)
{
if(b&0x1)
   ret=(ret*a)%c;
a=(a*a)%c;
b>>=1;
}
return ret;
}
int Euler(int n)
{
if(n==1)return 1;
int i,ret=n;
for(i=0;i<plen&&pl[i]<=n;++i)
    if(n%pl[i]==0)
    {
        ret-=ret/pl[i];
        while(n%pl[i]==0)n/=pl[i];
    }
if(n!=1)ret-=ret/n;
return ret;
}
void split(int n)
{
    flen=0;
    int i;
    for(i=0;i<plen&&pl[i]<=n;++i)
        if(n%pl[i]==0)
        {
            fac[flen][0]=pl[i];
            fac[flen][1]=0;
            while(n%pl[i]==0)n/=pl[i],++fac[flen][1];
            ++flen;
        }
    if(n!=1){fac[flen][0]=n;fac[flen++][1]=1;}
}
void dfs(int dep,int val)
{
    if(dep==flen)
    {
        ans+=(Euler(val)%p)*hpow(n,n/val-1,p);
        if(ans>=p)
            ans%=p;
        return;
    }
    int i;
    for(i=0;i<=fac[dep][1];++i)
    {
        dfs(dep+1,val);
        val*=fac[dep][0];
    }
}
int polya(int n)     
{   
    if(n==1)return 1%p;
    ans=0;
    split(n);
    dfs(0,1);
    return ans;
}
void mklist()
{
    int i,j;
    for(i=2;i*i<=N;++i)
        if(!ss[i])
            for(j=i;j*i<=N;++j)
                ss[i*j]=true;
    for(i=2;i<=N;++i)if(!ss[i])pl[plen++]=i;
}
int main()
{
    int t;
    mklist();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&p);
        printf("%d\n",polya(n));
    }
    
}
