#include<stdio.h>
const int N=31;
__int64 f[N];
int main()
{
    int n;
    f[0]=1,f[2]=3;
    for(int i=4;i<=30;i+=2)
        f[i]=f[i-2]*4-f[i-4];
    while(scanf("%d",&n),n!=-1)
        printf("%I64d\n",f[n]);
}
