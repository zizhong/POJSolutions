#include<cstdio>
#include<cstring>
int n,d,k,f[1024];
int cntbit(int x)
{
    int r=0;
    while(x) r+=(x&1),x>>=1;
    return r;
}
int main()
{
    scanf("%d%d%d",&n,&d,&k);
    for(int i=1;i<=n;i++)
    {
           f[i]=0;
           int k;
           scanf("%d",&k);
           for(int j=0;j<k;j++)
           {
                   int x;
                   scanf("%d",&x);
                   f[i]|=1<<(x-1);
           }
    }
    int ans=0,K=1<<d;
    for(int i=0;i<K;i++) if(cntbit(i)==k)
    {
         int x=i,tmp=0;
         for(int j=1;j<=n;j++) if((x|f[j])==x)
             tmp++;
         if(ans<tmp) ans=tmp;
    }
    printf("%d\n",ans);
}
