#include<stdio.h>
#include<string.h>
const int N=2500,M=370;
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
         memset(cnt,0,sizeof(cnt));
         for(int i=0;i<np;i++)
             while(n%pl[i]==0) cnt[i]++,n/=pl[i];
         if(n!=1) cnt[np]=1;
         __int64 ans=0;
         for(int i=0;i<=np;i++)
            ans+=(((__int64)cnt[i]+1)*(cnt[i]+2)/2)*(((__int64)cnt[i]+1)*(cnt[i]+2)/2);
         printf("%I64d\n",ans);
    }
}
