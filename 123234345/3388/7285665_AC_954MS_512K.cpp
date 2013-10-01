#include<stdio.h>
int ty[50001],a[40001];
unsigned int nn;
int n,k;
int ok(int x)
{
    nn=0;
    for(int i=1;i<=k;i++)
    {
          nn+=ty[i]/x;
          if(nn>=n) return 1;
    }
    return 0;
}
int half()
{
    int low=1,high=n+1,mid;
    while(low+1<high)
    {
         mid=low+high>>1;
         if(ok(mid)) low=mid;
         else high=mid;
    }
    return low;
}
int main()
{
   
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
          scanf("%d",&ty[i]);
    int ans=half();
    int j=0;
    for(int i=1;i<=k;i++)
    {
         for(nn=j;nn<n&&nn<j+ty[i]/ans;nn++)
               a[nn]=i;
         if(nn<j+ty[i]/ans) break;
         j+=(ty[i]/ans);
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++)
       printf("%d\n",a[i]);
    //scanf("%'d");
}
