#include<cstdio>
#include<cstring>
const int N=500010;
int d[N],q[N],head,tail;
const __int64 inf =1LL<<60;
__int64 sum[N],f[N];
__int64 dp(int x,int y)
{
       int p=x+1+y>>1; 
       return f[x]+
              (__int64)d[p]*(p-x-1-y+p)+
              sum[x]-sum[p-1]+
              sum[y]-sum[p];
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n,k;
         scanf("%d%d",&n,&k);
         for(int i=1;i<=n;i++) scanf("%d",&d[i]),sum[i]=sum[i-1]+d[i];
         head=tail=0;
         for(int i=1;i<=k;i++) f[i]=inf;
         f[0]=0;
         for(int i=k;i<=n;i++)
         {
              //add i-k
              while(head<tail && f[q[tail-1]]>f[i-k]) tail--;
              q[tail++]=i-k;
              while(head<tail-1&& dp(q[head],i)>dp(q[head+1],i)) head++;
              f[i]=dp(q[head],i);
              //printf("%d %I64d\n",q[head],f[i]);
         }
         printf("%I64d\n",f[n]);
    }
}
