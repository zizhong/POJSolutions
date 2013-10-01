#include<stdio.h>
int main()
{
    int t,n;
    while(scanf("%d%d",&t,&n)!=EOF&&t)
    {
        int i,sum=0;
        char s[11];
        while(t--)
        {
           scanf("%s%d",s,&i);
           sum+=i;
        }
        printf("%d\n",3*n-sum);
    }
}