#include<cstdio>
#include<cstring>
const int N=500010;
int d[N],q[N],head,tail;
const __int64 inf =1LL<<60;
__int64 sum[N],f[N];
__int64 cal(int x,int y)
{
       return 
              sum[y]-sum[x]-(__int64)(y-x)*d[x+1];
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
         for(int i=1;i<k;i++) f[i]=inf;
         f[0]=0;
         // X -cal(j,i) ;y f[j]
         for(int i=k;i<2*k&&i<=n;i++) f[i]=cal(0,i);
         for(int i=k*2;i<=n;i++)
         {
              //add i-k
              while(head<tail-1 && (f[i-k]-f[q[tail-1]])*(cal(q[tail-2],i)-cal(q[tail-1],i)) 
                                <= (f[q[tail-1]]-f[q[tail-2]])*(cal(q[tail-1],i)-cal(i-k,i)))
                   tail--;
              q[tail++]=i-k;
              while(head<tail-1 && f[q[head]]+cal(q[head],i) >=f[q[head+1]]+cal(q[head+1],i) ) head++;
              f[i]=f[q[head]]+cal(q[head],i);
              //printf("%d %I64d %I64d\n",q[head],cal(q[head],i),f[i]);
         }
         printf("%I64d\n",f[n]);
    }
}
