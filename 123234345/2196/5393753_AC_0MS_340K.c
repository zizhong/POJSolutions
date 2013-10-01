#include<stdio.h>
int main()
{
    int i,n;
    for(i=1000;i<10000;i++)
    {
        int sum10=i%10+i/1000%10+i/100%10+i/10%10,sum12=0,sum16=0;
        n=i;
        while(n)
        {
            sum12+=n%12;
            n/=12;
        }
        if(sum12!=sum10) continue;
        n=i;
        while(n)
        {
            sum16+=n%16;
            n/=16;
        }
        if(sum16!=sum10) continue;
        printf("%d\n",i);
    }
}
