#include<stdio.h>
int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int phi(int n)
{
    int ret=1,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            n/=i,ret*=i-1;
            while(n%i==0)
            {
               n/=i,ret*=i;
            }
        }
    }
    if(n>1) ret*=n-1;
    return ret;
}
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
         int v=phi(n);
         //printf("%d ..\n",v);
         int i=1,j;
         while(i*v<k) ++i;
         int cnt=(i-1)*v;
         for(j=1;cnt<k;j++)
         {
              if(gcd(j,n)==1) cnt++;
         }
         --j;
         j+=(i-1)*n;
         printf("%d\n",j);
    }
}
