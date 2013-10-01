#include<stdio.h>
int a[10001];
int main()
{
    int i;
    int t=1;
    a[0]=1;
    for(i=1;i<=10000;i++)
    {
        t*=i;
        while(t%10==0) t/=10;
        t%=100000;
        a[i]=t%10;
    }
    while(scanf("%d",&i)!=EOF)
    {
        printf("%5d -> %d\n",i,a[i]);
    }
}
