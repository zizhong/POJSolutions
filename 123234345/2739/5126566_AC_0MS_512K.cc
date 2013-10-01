#include<iostream>
#include<string.h>
using namespace std;
bool isprime[10001];
int prime[1500];
main()
{
      memset(isprime,true,sizeof(isprime));
      int i,j;
      for(i=2;i<=100;i++)
        if(isprime[i])
        for(j=i*i;j<=10000;j+=i)
          isprime[j]=false;
      int pcount,idx;
      for(idx=0,i=2;i<=10000;i++)
         if(isprime[i])
           prime[idx++]=i;
      pcount=idx;
      int n;
      while(cin>>n&&n)
      {
       int r=0;
       for(i=0;i<pcount;i++)
         for(j=i;j<pcount;j++)
         {
            int sum=0,k;
            for(k=i;k<=j;k++)
               sum+=prime[k];
            if(sum==n) r++;
            if(sum>n) break;
         }
       cout<<r<<endl;
      }
}
