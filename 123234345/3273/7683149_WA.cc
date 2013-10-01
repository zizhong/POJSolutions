#include<stdio.h>
const int N=100002;
int d[N];
int n,x;
int check(int x)
{
    for(int i=0;i<n;i++) if(d[i]>x) return 0;
    int ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
         if(sum+d[i]>x) sum=d[i],ans++;
         else sum+=d[i];
    }
    if(sum) ans++;
    return ans<=x;
}
int main()
{
    scanf("%d%d",&n,&x);
    int l=0,r=0,mid;
    for(int i=0;i<n;i++)
    {
       scanf("%d",&d[i]),r+=d[i];
       if(d[i]>l) l=d[i];
    }
    l--;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    scanf("%'d");
}
