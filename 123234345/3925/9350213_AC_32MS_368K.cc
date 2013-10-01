#include<cstdio>
#include<cstring>
const int N=16;
int g[N][N],w[N];
int n,m;
double solve(int x)
{
    double t1=0,t2=0;
    for(int i=0;i<n;i++) if(x&(1<<i))
        t1+=w[i];
    int d[N],v[N];
    int s=0;
    while(!(x&(1<<s))) s++;
    for(int i=0;i<n;i++)
       v[i]=0,d[i]=g[s][i];
    for(int i=0;i<n;i++) if(!(x&(1<<i)))
       v[i]=1;
    v[s]=1;
    while(true)
    {
        int min=0x3fffffff,tail=-1;
        for(int i=0;i<n;i++) if(v[i]==0 && min>d[i])
           min=d[i],tail=i;
        if(tail==-1) break;
        v[tail]=1;
        for(int i=0;i<n;i++) if(v[i]==0 && d[i]>g[tail][i])
            d[i]=g[tail][i];
    }
    for(int i=0;i<n;i++) if(x&(1<<i))
        t2+=d[i];
    return t2/t1;

}
int cntbit(int x)
{
    int r=0;
    while(x) r+=(x&1),x>>=1;
    return r;
}
int little(int r1,int r2)
{
    for(int i=0;i<n;i++) if((r1&(1<<i))!=(r2&(1<<i)))
        return (r1&(1<<i))?r1:r2;
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        for(int i=0;i<n;i++)
              scanf("%d",&w[i]);
        for(int i=0;i<n;i++)
           for(int j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        int K=1<<n;
        int ans=-1;
        double r=1e10;
        for(int k=0;k<K;k++) if(cntbit(k)==m)
        {
            double tmpr=solve(k);
            if(r>tmpr)  r=tmpr,ans=k;
            else if(tmpr == r) ans=little(ans,k);
        }
        int fir=0;
        for(int i=0;i<n;i++) if((1<<i)&ans)
        {
            if(fir) putchar(' ');fir=1;
            printf("%d",i+1);
        }
        puts("");
    }
}
