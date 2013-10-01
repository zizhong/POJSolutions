#include<stdio.h>
__int64 farey[1000001];
__int64 phi(__int64 n)
{
    __int64 ret=1,i;
    for(i=2;i*i<=n;i++)
      if(n%i==0)
      {
          n/=i,ret*i-1;
          while(n%i==0) n/=i,ret*=i;          
      }
    if(n>1) ret*=n-1;
    return ret;
}
void table()
{
     farey[2]=1;
     for(int i=3;i<=1000000;i++)
         farey[i]=farey[i-1]+phi(i);
}
int main()
{
    int n;
    table();
    while(scanf("%d",&n)&&n)
        printf("%I64d\n",farey[n]);
}
