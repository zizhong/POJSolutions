#include<stdio.h>
#include<stdlib.h>
const int N=10001;
__int64 c[N],t[N],st;
__int64 f[N]; 
int main()
{
    __int64 n;
    scanf("%I64d%I64d",&n,&st);
    for(int i=1;i<=n;i++)
        scanf("%I64d%I64d",&t[i],&c[i]);
    for(int i=n-1;i>=1;i--)
        t[i]+=t[i+1],c[i]+=c[i+1];
    f[n]=(st+t[n])*c[n];
    int q[N*2],head=0,tail=0;
    q[tail++]=n;
    for(int i=n-1;i>=1;i--)
    {
         while(tail-head>=2&&(f[q[head+1]]-f[q[head]]<c[i]*(t[q[head+1]]-t[q[head]])))
                head++;
         f[i]=f[q[head]]+(st+t[i]-t[q[head]])*c[i];
         if(f[i]>(st+t[i])*c[i]) f[i]=(st+t[i])*c[i];
         while(tail-head>=2&&((f[q[tail-1]]-f[q[tail-2]])*(t[i]-t[q[tail-1]])>(f[i]-f[q[tail-1]])*(t[q[tail-1]]-t[q[tail-2]])))
                   tail--;
         q[tail++]=i;
    }
    printf("%I64d\n",f[1]);
}
