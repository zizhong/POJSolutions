#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
         int sum=0,kut=0;
         while(n)
         {
             sum+=n;
             kut+=n;
             n=kut/k;
             kut%=k;
         }
         printf("%d\n",sum);
    }
}
