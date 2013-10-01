#include<stdio.h>
#include<math.h>
const double pi=acos(-1.0);
const int N=10100;
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
         int n,f;
         scanf("%d%d",&n,&f);
         f++;
         int r[N]={0};
         int low=0,high=0;
         for(int i=0;i<n;i++)
             scanf("%d",&r[i]),r[i]*=r[i],high+=r[i];
         high=high/n+1;
         while(low<high)
         {
              int mid=(low+high)>>1;
              int k=0;
              //printf("%6d%6d\n",low,high);
              if(mid==0)
              {
                   for(int i=0;i<n;i++)
                      k+=r[i];
                   if(k>=f) low=1;
                   else low=0;
                   break;
              }
              for(int i=0;i<n;i++)
                  k+=r[i]/mid;
              if(k>=f) low=mid;
              else high=mid-1;
              if(mid==((low+high)/2)) high++;
         }
         printf("%lf\n",low*pi);
    }
}
