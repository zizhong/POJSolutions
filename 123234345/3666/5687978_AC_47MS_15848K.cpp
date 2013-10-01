#include<stdio.h>
#include<stdlib.h>
const int inf=1000000000;
int min(int a,int b)
{
    return a<b?a:b;
}
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
const int N=2001;
int dp[N][N],a[N],v[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d",&a[i]);
         v[i]=a[i];
    }
    qsort(v,n,sizeof(v[0]),cmp);
    for(int i=0;i<n;i++)
    {
         if(a[0]>v[i])dp[0][i]=abs(v[i]-a[0]);
         else dp[0][i]=0;
         if(i>0) dp[i][0]=abs(v[0]-a[i])+dp[i-1][0];
    }
    for(int i=1;i<n;i++)
    {
       for(int j=1;j<n;j++)
       {
          int t=inf;
          t=min(t,min(dp[i-1][j]+abs(v[j]-a[i]),dp[i][j-1]));
          t=min(t,dp[i-1][j-1]+abs(v[j]-a[i]));
          dp[i][j]=t;
       }
    }
    int min=inf;
     for(int i=0;i<n;i++)   
        min=min>dp[n-1][i]?dp[n-1][i]:min;
    printf("%d\n",min);
}
