#include<stdio.h>
const int N=50010;
int d[N];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         for(int i=0;i<n;i++)
             scanf("%d",&d[i]);
         int mini=0,maxi=0,ans=-1;
         for(int i=1;i<n;i++)
         {
              if(d[i]<=d[mini])
              {
                   mini=maxi=i;
              }
              else if(d[i]>d[maxi])
              {
                   maxi=i;
                   if(ans<i-mini) ans=i-mini;
              }
         }
         printf("%d\n",ans);
    }
}
