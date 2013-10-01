#include<cstdio>
#include<cstring>
const int N=210,inf=0x3fffffff;
int  d[N],n,f[N][N][N],v[N],num[N],cnt,pre[N];
int dfs(int i,int j,int k)
{
    if(f[i][j][k]>0) return f[i][j][k];
    int tmp=dfs(i,j-1,0)+(num[j]+k)*(num[j]+k);
    int p=pre[j];
    while(p>=i)
    {
         int temp=dfs(i,p,k+num[j])+dfs(p+1,j-1,0);
         if(temp>tmp) tmp=temp;
         p=pre[p];
    }
    return f[i][j][k]=tmp;
    
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int nc=1;nc<=T;nc++)
    {         
         scanf("%d",&n);
         for(int i=1;i<=n;i++) scanf("%d",&d[i]);
         //compress
         int tn=0;
         for(int i=1;i<=n;i++)
         {
                int j=i;
                while(d[j]==d[i]) j++;
                v[++tn]=d[i];
                num[tn]=j-i;
                i=j-1;
         }
         cnt=tn;
         int col[N]={0};
         for(int i=1;i<=cnt;i++)
         {
              pre[i]=col[v[i]];
              col[v[i]]=i;
         }
         //dp
         for(int i=1;i<=cnt;i++) f[i][i-1][0]=0;
         for(int i=1;i<=cnt;i++) for(int k=0;k<=n;k++)
               f[i][i][k]=(num[i]+k)*(num[i]+k);
         printf("Case %d: %d\n",nc,dfs(1,cnt,0));
    }
}
