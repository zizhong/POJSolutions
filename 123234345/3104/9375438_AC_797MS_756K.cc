#include<cstdio>
#include<cstring>
int n,k,d[100010];
bool ok(__int64 x)
{
     __int64 ret=0;
     for(int i=0;i<n;i++) if(d[i]>x)
          ret+=(d[i]-x+k-2)/(k-1);
     return ret <= x;
}
int main()
{
    scanf("%d",&n);
    int maxd=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&d[i]);
        if(maxd<d[i]) maxd=d[i];
    }
    scanf("%d",&k);
    if(k==1) {printf("%d\n",maxd);return 0;}
    
    __int64 l=1,r=maxd;
    if(ok(l)) printf("%I64d\n",l);
    else
    {
        
        while(l+1<r)
        {
              __int64 mid=l+r>>1;
              if(ok(mid)) r=mid;
              else l=mid;           
        }
        printf("%I64d\n",r);
    }
}
