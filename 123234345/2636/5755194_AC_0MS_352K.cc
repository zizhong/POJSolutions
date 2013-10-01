#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        int h=n;
        while(h--)
        {
            int a;
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",sum-n+1);
    }
}
