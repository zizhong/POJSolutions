#include<cstdio>
#include<cstring>
const int N=500010;
int d[N],q[N],head,tail;
const __int64 inf =1LL<<60;
__int64 sum[N],f[N];
__int64 cal(int x,int y)
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
         for(int i=1;i<k;i++) f[i]=inf;
         f[0]=0;
         // X -cal(j,i) ;y f[j]
         for(int i=k;i<=n;i++)
         {
              //add i-k
              while(head<tail-1 && (f[i-k]-f[q[tail-1]])*(cal(q[tail-2],i)-cal(q[tail-1],i)) 
                                <= (f[q[tail-1]]-f[q[tail-2]])*(cal(q[tail-1],i)-cal(i-k,i)))
                   tail--;
              q[tail++]=i-k;
              while(head<tail-1 && f[q[head]]+cal(q[head],i) >=f[q[head+1]]+cal(q[head+1],i) ) head++;
              f[i]=q[head]+cal(q[head],i);
         }
         printf("%I64d\n",f[n]);
    }
}
