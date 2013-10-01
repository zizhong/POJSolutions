#include<stdio.h>
#include<math.h>
const double pi=acos(-1.0);
const int N=10100;
const int eps=100000;
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
         __int64 n,f;
         scanf("%I64d%I64d",&n,&f);
         f++;
         __int64 r[N]={0};
         __int64 low=0,high=0;
         for(int i=0;i<n;i++)
             scanf("%I64d",&r[i]),r[i]*=(r[i]*eps),high+=r[i];
         high=high/n;
         while(low+1<high)
         {
              __int64 mid=(low+high)>>1;
              __int64 k=0;
             
              for(int i=0;i<n;i++)
                  k+=r[i]/mid;
              if(k>=f) low=mid;
              else high=mid;
         }
         printf("%lf\n",low*pi/eps);
    }
}
