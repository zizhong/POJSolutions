#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=100010;
__int64 n,m,sum[N];
int d[N];
int q1[N],h1,t1;
__int64 f[N];
int main()
{
    while(scanf("%I64d%I64d",&n,&m)==2)
    {
         for(int i=1;i<=n;i++) 
             scanf("%d",&d[i]),sum[i]=sum[i-1]+d[i];
         h1=t1=0;
         f[0]=0;
         int flag=1;
         int t=0;
         for(int i=1;i<=n;i++)
         {
             while(i>t && sum[i]-sum[t]>m) t++;
             if(i==t) flag=0;
             while(h1<t1 && d[q1[t1-1]]<d[i]) t1--;
             q1[t1++]=i;
             
             while(h1<t1 && sum[i] - sum[q1[h1]] > m) h1++;
             f[i]=f[t]+d[q1[h1]];
             for(int j=h1;j<t1;j++) if(f[i]>f[q1[j]]+d[q1[j+1]])f[i]=f[q1[j]]+d[q1[j+1]];
             
         }
         if(flag)
             printf("%I64d\n",f[n]);
         else puts("-1");
    }
}
