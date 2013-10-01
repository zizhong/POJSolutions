#include<stdio.h>
const int N=100010;
int d[N],f[N],cnt;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
         for(int i=0;i<n;i++)
             scanf("%d",&d[i]);
         cnt=1;
         f[1]=d[0];
         for(int i=1;i<n;i++)
         {
              if(d[i]>f[cnt])
              {
                   f[++cnt]=d[i];
                   continue;
              }
              if(d[i]<d[1])
              {
                   d[1]=d[i];
                   continue; 
              }
              int l=1,r=cnt;
              while(l<=r)
              {
                   int mid=l+r>>1;
                   if(f[mid]<d[i]) l=mid+1;
                   else r=mid-1;
              }
              f[l]=d[i];
         }
         printf("%d\n",cnt);
    }
}
