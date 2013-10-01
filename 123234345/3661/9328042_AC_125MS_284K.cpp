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
    int tmp=0;
    for(int i=0;i<=n;i++)
    {
         if(tmp<f[i]) tmp=f[i];         
         for(int j=1;j<=m&&i+2*j<=n;j++)
               if(f[i+2*j]<tmp+sum[i+j]-sum[i])
                   f[i+2*j]=tmp+sum[i+j]-sum[i];
    }
    printf("%d\n",tmp);
    
}
