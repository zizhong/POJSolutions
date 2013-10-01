#include<stdio.h>
const int N=40000;
int v[N+1]={1,1},pl[N],plen;
int M;
int fac[32][2],flen;
int ans=0;
int Pow(int a,int b)
{
int ret=1%M;
a%=M;
while(b)
{
if(b&0x1)
   ret=(ret*a)%M;
a=(a*a)%M;
b>>=1;
}
return ret;
}
void table()
{
     for(int i=2;i<N;i++)
           if(v[i]==0)
           {
                pl[plen++]=i;
                for(int j=i+i;j<40000;j+=i) v[j]=1;
           }
}
int phi(int n)
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
     for(int i=0;i<plen&&pl[i]<=n;++i)
          if(n%pl[i]==0)
          {
              fac[flen][0]=pl[i];
              fac[flen][1]=0;
              while(n%pl[i]==0)  ++fac[flen][1],n/=pl[i];
              ++flen;
          }
     if(n!=1) fac[flen][0]=n,fac[flen++][1]=1;
}
int n;
void dfs(int dep,int val)
{
     if(dep==flen)
     {
           ans+=phi(val)%M*Pow(n,n/val-1);
           ans%=M;
           return ;
     }
     for(int i=0;i<=fac[dep][1];++i)
     {
           dfs(dep+1,val);val*=fac[dep][0];
     }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         
         scanf("%d%d",&n,&M);
         
         if(n==1) ans=1;
         else
         {
             ans=0;
             split(n);
             dfs(0,1);
         }
         printf("%d\n",ans);
    }
}
