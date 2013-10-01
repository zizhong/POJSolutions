#include<stdio.h>
const int N=100001;
int d[N];
int cnt(int x,int n)
{
    int ans=0,sum=0;
    for(int i=0;i<=n;i++)
    {
         if(sum+d[i]>x) ans++,sum=d[i];
         else sum+=d[i];
    }
    return ans;
}
int main()
{
    int n,x,r=0,mid;
    scanf("%d%d",&n,&x);
    int l=0;
    for(int i=0;i<n;i++)
    {
       scanf("%d",&d[i]),r+=d[i];
       if(d[i]>l) l=d[i];
    }
    d[n]=0;
    while(l<r)
    {
        mid=(l+r)>>1;
        //printf("%d %d %d : %d\n",l,r,mid,cnt(mid,n));
        if(cnt(mid,n)<=x) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    //scanf("%'d");
}
