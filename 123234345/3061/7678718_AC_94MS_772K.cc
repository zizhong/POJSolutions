#include<stdio.h>
const int N=100001;
int d[N];
int main()
{
    int T,n,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&sum);
        for(int i=1;i<=n;i++)
             scanf("%d",&d[i]),d[i]+=d[i-1];
        if(d[1]>=sum)
        {
             printf("%d\n",d[1]>=sum?1:0);
             continue;
        }
        int ans=n+N;
        int head=1,tail=1;
        for(int i=2;i<=n;i++)
        {
            int flag=0;    
            while(head+1<=i&&d[i]-d[head-1]>=sum) head++,flag=1;
            if(flag) head--;
            //printf("%d: %d %d\n",i,head,d[i]-d[head-1]);
            if(d[i]-d[head-1]>=sum&&ans>i-head+1) ans=i-head+1;
        }
        printf("%d\n",ans<=n?ans:0);
    }
}
