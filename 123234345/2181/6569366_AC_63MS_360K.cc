#include<stdio.h>
int _max(int a,int b){return a>b?a:b;}
int main()
{
    int n,a;
    scanf("%d%d",&n,&a);
    int max1=a,max0=0;
    while(--n)
    {
        scanf("%d",&a);
        int t=_max(max0+a,max1);
        max0=_max(max0,max1-a);
        max1=t;
    }
    printf("%d\n",_max(max1,max0));
}
