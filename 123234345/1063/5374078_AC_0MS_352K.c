#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m1=0,m2=0;
        scanf("%d",&n);
        int t=n;
        while(n--)
        {
           int i;
           scanf("%d",&i);
           if(n%2) m1+=i;
           else m2+=i;           
        }
        if(t%2||abs(m1-m2)<2) printf("YES\n");
        else printf("NO\n");
    }
}
