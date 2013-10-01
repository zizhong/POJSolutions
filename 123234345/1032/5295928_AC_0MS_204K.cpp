#include<stdio.h>
int main()
{
    int n,a[1000]={0},i=2,j;
    scanf("%d",&n);
    while(n>=i)
    {
       a[i]=i;
       n-=i;
       i++;
    }
    j=i-1;
    while(n)
    {
       a[j--]++;
       if(j<2) j=i-1;
       n--;
    }
    for(j=2;j<i;j++)
    {
       if(j!=2) printf(" ");
       printf("%d",a[j]);
    }
    printf("\n");
}
