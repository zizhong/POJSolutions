#include<stdio.h>
#include<string.h>
const int N=431;
int pcnt,prime[N/4];
void getPrime(int n)
{
     int flag[N+1];
     memset(flag,0,sizeof(flag));
     pcnt=0;
     for(int i=2;i<=n;i++)
         if(!flag[i]) 
         {
              prime[pcnt++]=i;
              for(int j=i*i;j<=n;j+=i)
                  flag[j]=1;
         }         
}
int cal(int n,int p)
{
    if(n<p) return 0;
    return n/p + cal(n/p,p);
}
int main()
{
    getPrime(N);
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        __int64 cnt=1;
        for(int i=0;prime[i]<=n&&i<pcnt;i++)
        {
            int t=cal(n,prime[i])-cal(n-k,prime[i])-cal(k,prime[i]);
            cnt*=(t+1);
        }
        printf("%I64d\n",cnt);
    }
}
