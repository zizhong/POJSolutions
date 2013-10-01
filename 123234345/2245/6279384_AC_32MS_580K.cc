#include<stdio.h>
#include<stdlib.h>
int a[14],n;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int fir=0;
    while(scanf("%d",&n),n)
    {
          if(fir) puts("");
          fir=1;
          for(int i=0;i<n;i++) scanf("%d",&a[i]);
          qsort(a,n,sizeof(a[0]),cmp);
          int k=(1<<n); 
          for(int i=k;i>=0;i--)
          {
                  int cnt=0;
                  for(int j=0;j<n;j++) if((i>>j)&1) cnt++;
                  if(cnt!=6) continue;
                  cnt=0;
                  for(int j=n-1;j>=0;j--)
                  if((i>>j)&1)
                  {
                        cnt++;
                        printf("%d%c",a[n-j-1],cnt!=6?' ':'\n');
                  }
          }
    }
}
