#include<cstdio>
#include<cstring>
int main()
{
    int n;
    scanf("%d",&n);
    double minarea=1e10;
    int ans[3];
    for(int i=1;(__int64)i*i*i<=n;i++) if(n%i==0)
    {
         for(int j=i;j<=n*1.0/(i*j);j++) if(n/i%j==0)
         {
              int k=n/i/j;
              if(k<i) break;
              int area=2*(i*j+j*k+k*i);
              if(area<minarea) minarea=area,ans[0]=i,ans[1]=j,ans[2]=k;
         }
    }
    printf("%d %d %d\n",ans[0],ans[1],ans[2]);
}
