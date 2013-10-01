#include<stdio.h>
int map[1001][1001];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ii=1;ii<=T;ii++)
    {
        int n,m,k,tt,a,b;
        __int64 ans=0;
        int t[1001]={0};
        scanf("%d%d%d",&n,&m,&k);
        while(k--)
                  scanf("%d%d",&a,&b),map[a][b]=ii,t[b]++;
        for(int i=1;i<=n;i++)
        {
                tt=0;
                for(int j=1;j<=m;j++)
                {
                   if(map[i][j]==ii) ans+=tt,t[j]--;
                   tt+=t[j];
                }                
        }
        printf("Test case %d: %I64d\n",ii,ans);
    }
}
