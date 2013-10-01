#include<stdio.h>
const int VMax=100001;
const int inf=99999999;
const int N=11;
int nk[N],dk[N],f[VMax],n,v;
int main()
{
    while(scanf("%d",&v)!=EOF)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&nk[i],&dk[i]);
        for(int i=0;i<=v;i++) f[i]=0;
        for(int i=1;i<=n;i++)
        {
            int k=1;
            while(k<nk[i])
            {
                for(int j=v;j>=k*dk[i];--j)
                    if(f[j]<f[j-k*dk[i]]+dk[i]*k)
                    f[j]=f[j-k*dk[i]]+dk[i]*k;
                nk[i]-=k;
                k*=2;
            }
            for(int j=v;j>=nk[i]*dk[i];--j)
               if(f[j]<f[j-nk[i]*dk[i]]+dk[i]*nk[i])
                   f[j]=f[j-nk[i]*dk[i]]+dk[i]*nk[i];
        }
        printf("%d\n",f[v]);
    }
}
