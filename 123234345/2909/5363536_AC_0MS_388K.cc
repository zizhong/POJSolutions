#include<stdio.h>
#include<cmath>
#include<string.h>
const int MAX=32768;
bool flag[MAX];
void prime()
{
     int max=int(sqrt(MAX));
     int i,j;
     memset(flag,true,sizeof(flag));
     flag[0]=flag[1]=false;
     for(i=2;i<=max;i++)
        if(flag[i])
        for(j=i*i;j<=MAX;j+=i)
            flag[j]=false;
}
int main()
{
    int n;
    prime();
    while(scanf("%d",&n)&&n)
    {
        int i,count=0;
        for(i=1;i<=n-i;i++)
            if(flag[i]&&flag[n-i])
              count++;
        printf("%d\n",count);
    }
}
