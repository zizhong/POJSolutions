#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d",&n);
    t=n;
    while(n--)
    {
        __int64 s,e;
        scanf("%I64d%I64d",&s,&e);
        printf("Scenario #%d:\n",t-n);
        printf("%I64d\n\n",(s+e)*(e-s+1)/2);
    }
}
