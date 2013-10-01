#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
        printf("%d\n",n*k/(k-1)-1);
}
