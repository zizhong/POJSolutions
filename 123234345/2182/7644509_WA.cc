#include<stdio.h>
const int N=8001;
int d[N],v[N],cal[N],hv[N];
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=2;i<=n;i++) scanf("%d",&d[i]);
    for(i=2;i<=n;hv[v[i]]=1,i++)
    if(cal[i]==0)
    {
         sum=0;
         for(j=i+1;j<=n;j++) if(d[i]>=d[j])
         {
             sum++;
             if(d[i]==d[j]) v[j]=sum;
         }
         for(j=i+1;j<=n;j++) if(d[i]==d[j]) v[j]=sum-v[j],cal[j]=1;
         v[i]=sum+d[i]+1;
    }
    else v[i]=v[i]+d[i]+1;
    for(int i=1;i<=n;i++) if(hv[i]==0)
    {
         printf("%d\n",i);
         break;
    }
    for(int i=2;i<=n;i++) printf("%d\n",v[i]);
    //scanf("%'d");
}
