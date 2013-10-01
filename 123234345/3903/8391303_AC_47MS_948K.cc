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
              int l=1,r=cnt;
              while(l<=r)
              {
                   int m=l+r>>1;
                   if(f[m]<d[i]) l=m+1;
                   else r=m-1;
              }
              if(l>cnt) cnt++;
              f[l]=d[i];
         }
         printf("%d\n",cnt);
    }
}
