#include<cstdio>
#include<cstring>
int dp[10][50][50];
int n;
int dfs(int pre,int post,int d)
{
    if(d==-1) return pre==post;
    if(dp[d][pre][post]!=-1)return dp[d][pre][post];
    int &ans=dp[d][pre][post];
    ans=0;
    for(int i=0;i<10;i++)
    {
         int npre=pre,npost=post;
         if(d>=n/2) npre+=i;
         else npost+=i;
         ans+=dfs(npre,npost,d-1);
    }
    return ans;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    printf("%d\n",dfs(0,0,n-1));
    scanf("%'d");
}
