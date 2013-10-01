#include<stdio.h>
const int N=50001;
int max(int a,int b){return a>b?a:b;}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
          int n,a[N]={0},f[N][4]={0},m;
          scanf("%d",&n);
          for(int i=1;i<=n;i++) scanf("%d",&a[i]);
          scanf("%d",&m);
          for(int i=1;i<=n-m+1;i++)
          {
               for(int j=1;j<m;j++)
                   a[i]+=a[i+j];
               f[i][1]=a[i]>a[i-1]?a[i]:a[i-1];
          }
          for(int i=1;i<=n-m+1;i++)
                for(int j=1;j<=3;j++)
                {
                      int k=i-m>0?i-m:0;
                      f[i][j]=max(f[i-1][j],f[k][j-1]+a[i]);  
                }
          int ans=0;
          for(int i=1;i<=n+m-1;i++)
                ans=max(ans,f[i][3]);
          printf("%d\n",ans);
    }
}
