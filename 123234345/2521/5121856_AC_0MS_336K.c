#include<stdio.h>
int main()
{
    int n,m,p,c;
    while(scanf("%d%d%d%d",&n,&m,&p,&c))
    {
        if(n==0&&m==0&&p==0&&c==0) break;
        printf("%d\n",n+c-(m+c-p));
    }
}
