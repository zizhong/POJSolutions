#include<stdio.h>
const int Mod=10007;
int GetPow(int a,int n)
{
    if(n==0) return 1;
    if(n==1) return a;
    int r=1;
    r=GetPow(a,n/2)*GetPow(a,n/2)%Mod;
    if(n&1) r=r*a%Mod;
    return r;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int ans=(GetPow(4,n-1)+GetPow(2,n-1))%Mod;
        printf("%d\n",ans);
    }
}
