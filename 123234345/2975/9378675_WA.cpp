#include<cstdio>
#include<cstring>
const int N=1024;
int d[N],bin[N][32],sum[32];

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         
         for(int i=0;i<n;i++)
              scanf("%d",&d[i]);
         memset(sum,0,sizeof(sum));
         for(int i=0;i<n;i++)
            for(int j=0;j<31;j++)
               bin[i][j]=((d[i]>>j)&1),sum[j]+=bin[i][j];
         int cps[N]={0},odd=0;
         for(int i=0;i<31;i++) if(sum[i]&1)
         {
              odd++;
              for(int j=0;j<n;j++)
                  cps[j]+=bin[j][i];
         }
         int ans=0;
         if(odd)
         for(int i=0;i<n;i++)
             ans+=(cps[i]==odd);
         printf("%d\n",ans);
    }
}
