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
         int cnt[M],nt=0;
         for(int i=0;i<np;i++)
         {
             if(n<pl[i]*pl[i]) break;
             if(n%pl[i]==0)
             {
                cnt[nt]=0;
                while(n%pl[i]==0) cnt[nt]++,n/=pl[i];
                nt++;
             }
         }
         if(n!=1) cnt[nt++]=1;
         __int64 ans=0,tmp;
         for(int i=0;i<nt;i++)
         {
            tmp=((__int64)cnt[i]+1)*(cnt[i]+2)/2;
            ans+=tmp*tmp;
         }
         printf("%I64d\n",ans);
    }
}
