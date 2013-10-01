#include<cstdio>
#include<cstring>
const int inf=0x3fffffff;
int d[10010],sum[10010],f[10010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
         scanf("%d",&d[i]),sum[i]=sum[i-1]+d[i];
    for(int i=1;i<=n;i++)  f[i]=-inf;
    for(int i=0;i<=n;i++) if(f[i]>-inf)
         for(int j=1;j<=m&&i+2*j<=n;j++)
               if(f[i+2*j]<f[i]+sum[i+j]-sum[i])
                   f[i+2*j]=f[i]+sum[i+j]-sum[i];
    int ans=0;
    for(int i=1;i<=n;i++) if(f[i]>ans)
         ans=f[i];
    printf("%d\n",ans);
    
}
