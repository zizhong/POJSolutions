#include<stdio.h>
#include<stdlib.h>
const int N=10001;
int c[N],t[N],st;
__int64 f[N]; 
int main()
{
    int n;
    scanf("%d%d",&n,&st);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&t[i],&c[i]);
    for(int i=n-1;i>=0;i--)
        t[i]+=t[i+1],c[i]+=c[i+1];
    f[n]=(st+t[n])*c[n];
    int q[N*2],head=0,tail=0;
    q[tail++]=n;
    for(int i=n-1;i>=1;i--)
    {
         while(tail-head>=2&&(f[q[head+1]]-f[q[head]]<c[i]*(t[q[head+1]]-t[q[head]])))
                head++;
         f[i]=f[q[head]]+(st+t[i]-t[q[head]])*c[i];
         while(tail-head>=2&&((f[q[tail]]-f[q[tail-1]])*(t[i]-t[q[tail]])>(f[i]-f[q[tail]])*(t[q[tail]]-t[q[tail-1]])))
                   tail--;
         q[tail++]=i;
    }
    printf("%I64d\n",f[1]);
}
