#include<cstdio>
#include<cstring>
const int N=7,M=823543;
int d[N][N];
int pre[M][N],cnt=0;
int f[N],n;
void dfs(int d)
{
     if(d==0)
     {
          for(int i=0;i<n;i++)
               pre[cnt][i]=f[i];
          cnt++;
          return ;
     }
     for(int i=0;i<n;i++)
     {
          f[d-1]=i;
          dfs(d-1);
     }
}
int main()
{
    int n;
    while(scanf("%d",&n),n!=-1)
    {
         for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
                  scanf("%d",&d[i][j]);
         int ans=100000,tmp,tmp2,tmp3;
         cnt=0;
         dfs(n);
         for(int i=0;i<cnt;i++)
         {
              tmp2=0;
              for(int j=0;j<n;j++)
              {
                   tmp=0;
                   for(int k=0;k<n;k++)
                   {
                       tmp3=k+pre[i][k];
                       if(tmp3>=n) tmp3-=n;
                       tmp+=d[tmp3][j];
                   }
                   if(tmp>tmp2) tmp2=tmp;
              }
              if(tmp<ans) ans=tmp;
         }
         printf("%d\n",ans);
    }
}
