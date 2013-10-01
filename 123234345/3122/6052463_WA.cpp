#include<stdio.h>
const double pi=3.14159265358979;
int h[10001];
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
         int n,f;
         scanf("%d%d",&n,&f);
         f++;
         for(int i=0;i<n;i++)
            scanf("%d",&h[i]);
         int low=1,high=100000000,mid;
         while(low<high)
         {
               mid=(low+high)>>1;
               int k=0;
               for(int i=0;i<n;i++)
                  k+=h[i]*h[i]/mid;
               if(k<f)
                   high=mid-1;
               else low=mid;
               if(mid==(low+high)>>1)  low++;             
         }
         printf("%.4f\n",low);
    }
}
