#include<cstdio>
#include<cstring>
const int N=50010;
int type[1000000],num[1000000],lvl;
void insert(int x)
{
    if(type[x]==lvl) num[x]++;
    else type[x]=lvl,num[x]=1;
}
int findx(int x)
{
    if(type[x]!=lvl) return 0;
    else return num[x];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int d,n;
        scanf("%d%d",&d,&n);
        int zero=1,sum=0;
        ++lvl;
        insert(0);
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum=(sum+x)%d;
            ans+=findx(sum);
            insert(sum);
        }
        printf("%lld\n",ans);
    }
}
