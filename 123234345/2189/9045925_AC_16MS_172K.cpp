#include<cstdio>
#include<cstring>
const int N=1010;
int cow[N],sum[N];
int n,p,c;
int main()
{
    scanf("%d%d%d",&n,&p,&c);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cow[x+1]++;
    }
    for(int i=2;i<=p;i++) sum[i]=cow[i]+sum[i-1];
    int ans=0;
    for(int l=p-1;l>0;l--)
    {
        for(int i=1;i+l<=p;i++)
        {
            int j=i+l;
            if(sum[j]-sum[i]<=c) {ans=l;break;}
        }
        if(ans) break;
    }
    printf("%d\n",ans);
}
