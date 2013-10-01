#include<stdio.h>
int main()
{
    int i,sum=0,n;
    scanf("%d",&n);
    for(i=1;sum<n||(sum-n)%2;i++)
        sum+=i;
    printf("%d\n",i-1);
}
