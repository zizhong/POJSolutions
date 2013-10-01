#include<cstdio>
#include<cstring>
int num[12];
int main()
{
    int n,w;
    while(scanf("%d%d",&n,&w),n)
    {
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            num[x/w]++;
        }
        int cnt=11;
        while(!num[cnt]) cnt--;

        double d=1.0/cnt;
        int max=0;
        for(int i=0;i<=cnt;i++)
            if(max<num[i]) max=num[i];
        double ans=0,dark=1.0;
        for(int i=0;i<=cnt;i++)
        {
            ans+=num[i]*1.0/max*dark;
            dark-=d;
        }
        printf("%.8f\n",ans+0.01);
    }
}
