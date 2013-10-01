#include<stdio.h>
int n,k,m;
int ans(int num)
{
    return num?((k+ans(num-1))%num):0;
}
int main()
{
    while(scanf("%d%d%d",&n,&k,&m)&&(m||n||k))
         printf("%d\n",(ans(n-1)+m)%n+1);
}
