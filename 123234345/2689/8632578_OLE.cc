#include<stdio.h>
#include<string.h>
const int N=1<<16,M=1000010;
int pl[N],np,v[N],p[M];
void table()
{
     for(int i=2;i<N;i++)
         if(!v[i])
         {
              pl[np++]=i;
              for(int j=i+i;j<N;j+=i) v[j]=1;
         }
}
__int64 tp[M];
int main()
{
    table();
    __int64 l,u;
    while(scanf("%I64d%I64d",&l,&u)==2)
    {
         int cnt=0;
         memset(p,0,sizeof(p));
         for(int i=0;i<np&&(__int64)pl[i]*pl[i]<=u;i++)
         {
              __int64 j=l/pl[i]+(l%pl[i]>0);
              if(j==1) j++; 
              j*=pl[i];
              printf("<%d %I64d>\n",i,j);
              for(;j<=u;j+=pl[i]) p[j-l]=1;
         }
         if(l==1) p[0]=1;
         for(__int64 i=l;i<=u;i++)
         {
              if(p[i-l]==0) tp[cnt++]=i;
         }
         if(cnt<2) puts("There are no adjacent primes.");
         else
         {
             int pos=0;
             for(int i=1;i<cnt-1;i++)
                  if(tp[i+1]-tp[i]<tp[pos+1]-tp[pos])
                        pos=i;
             printf("%I64d,%I64d are closest, ",tp[pos],tp[pos+1]);
             pos=0;
             for(int i=1;i<cnt-1;i++)
                  if(tp[i+1]-tp[i]>tp[pos+1]-tp[pos])
                        pos=i;
             printf("%I64d,%I64d are most distant.\n",tp[pos],tp[pos+1]);
         }
    }
}
