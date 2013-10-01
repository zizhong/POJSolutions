#include<stdio.h>
const int N=100002;
int d[N];
int n,x;
int check(int xx)
{
    for(int i=0;i<n;i++) if(d[i]>xx) return 0;
    int ans=0,sum=0;
    for(int i=0;i<n;i++)
    {
         if(sum+d[i]>xx) sum=d[i],ans++;
         else sum+=d[i];
    }
    if(sum) ans++;
    //printf("<%d : %d>\n",xx,ans);
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
        //printf("%d %d %d\n",l,r,mid);
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    scanf("%'d");
}
