#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        char s[16];
        int high=11,low=-1;
        while(getchar(),gets(s),strcmp(s,"right on"))
        {
             if(strcmp(s,"too high")==0) high=n-1<high?n-1:high;
             else low=n+1>low?n+1:low;
             //printf("low=%d,high=%d\n",low,high);
             scanf("%d",&n);
        }
        if(n>=low&&n<=high) printf("Stan may be honest\n");
        else printf("Stan is dishonest\n");
    }
}
