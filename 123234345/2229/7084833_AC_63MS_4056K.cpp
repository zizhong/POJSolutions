#include<stdio.h>
const int mod = 1000000000;
int f[1000001];
int main()
{
    int n;
    scanf("%d",&n);
    f[1]=1,f[2]=2;
    for(int i=3;i<=n;i++)
       if(i&1) f[i]=f[i-1];
       else f[i]=(f[i-2]+f[i/2])%mod;
    printf("%d\n",f[n]);
    }
