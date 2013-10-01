#include<stdio.h>
const int N=1000000;
int a[N+2],b[N+2];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=n;i>=1;i--)
        scanf("%d%d",&a[i],&b[i]);
    int t=0;
    for(i=1;i<=n;i++)
    {
        a[i]+=b[i]+t;
        t=a[i]/10;
        a[i]%=10;
    }
    if(t!=0) a[n++]=t;
    for(i=n;i>=1;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
