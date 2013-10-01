#include<cstdio>
#include<cstring>
int d[16],f[16][1<<12];
const int inf=0x3fffffff,mod=100000000;
int n,m,r,x;
void dfs(int i,int k,int t)
{
     if(i>=m)
     {
           f[r][k]=(f[r][k]+x)%mod;
           return ;
     }
     if(((t>>i)&1) || (i>0 && (k>>(i-1))&1) ) {dfs(i+1,k,t);return ;}
     dfs(i+1,k|(1<<i),t);
     dfs(i+1,k,t);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
         d[i]=0;
         for(int j=0;j<m;j++)
         {
               int x;
               scanf("%d",&x);
               d[i]=d[i]*2+(!x);
         }
    }
    int K=1<<m;
    for(int i=0;i<=n;i++)
         for(int j=0;j<K;j++)
             f[i][j]=0;
    f[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<K;j++) if(f[i][j]!=0)
        {
             r=i+1,x=f[i][j];   
             dfs(0,0,j|d[i+1]);
        }
    int ans=0;
    for(int i=0;i<K;i++)
        ans=(ans+f[n][i])%mod;
    printf("%d\n",ans);
}
