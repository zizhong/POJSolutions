#include<stdio.h>
const int N=500000,M=41539;
int v[N],pl[N],np;
void table()
{
     v[1]=1;
     for(int i=2;i<N;i++) if(!v[i])
     {
          pl[np++]=i;
          for(int j=i+i;j<N;j+=i) v[j]=1;
     }
}
int cnt[M];
int main()
{
    table();
    int T;
    for(scanf("%d",&T);T--;)
    {
         int n;
         scanf("%d",&n);
         if(n==1)
         {
              puts("0");
              continue;
         }
         int k=0;
         cnt[k]=0;
         while(n!=1)
         {
             cnt[k]=0;
             while(n%pl[k]==0) cnt[k]++,n/=pl[k];
             k++;
         }
         __int64 ans=0;
         for(int i=0;i<k;i++)
            ans+=(((__int64)cnt[i]+1)*(cnt[i]+2)/2)*(((__int64)cnt[i]+1)*(cnt[i]+2)/2);
         printf("%I64d\n",ans);
    }
}
