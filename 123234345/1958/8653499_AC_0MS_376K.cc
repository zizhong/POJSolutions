#include<stdio.h>
const int N=13;
int f[N],g[N];
int main()
{
    f[1]=g[1]=1;
    for(int i=2;i<=12;i++) f[i]=2*f[i-1]+1;
    for(int i=2;i<=12;i++)
    {
        g[i]=10000000;
        for(int j=1;j<i;j++)
           if(g[i]>g[j]*2+f[i-j]) g[i]=g[j]*2+f[i-j];
    }
    for(int i=1;i<=12;i++) printf("%d\n",g[i]);
}
