#include<stdio.h>
__int64 solve(int n,int k)
{
       __int64 sum=0;
       if(n>k)
       {
        sum=(__int64)(n-k)*k;
        n=k;
       }
       int nDiv=k/n;
       while (n>1)
       {//n尚未处理
        int nNex=k/(nDiv+1);
        if(n==nNex)
        {
         sum+=k%n;
         n--;nDiv=k/n;
         continue;
        }
        int Low=k%n,High=k%(nNex+1);
        sum+=((__int64)(Low+High)*(n-nNex)>>1);
        n=nNex;++nDiv;
       }
       return sum;
}
int main()
{
       int N,K;
       while (EOF!=scanf("%d%d",&N,&K))
         printf("%I64d\n",solve(N,K));
       return 0;
}
