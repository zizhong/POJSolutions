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
         for(int i=0;i<n;i++)
         {
              if(d[i]<d[i+1])
              {
                   mini=maxi=i++;
              }
              while(d[i]>d[mini])
              {
                  if(d[i]>d[maxi]) maxi=i;
                  i++;
              }
              if(ans<maxi-mini) ans=maxi-mini;
              i=maxi;
         }
         printf("%d\n",ans);
    }
}
