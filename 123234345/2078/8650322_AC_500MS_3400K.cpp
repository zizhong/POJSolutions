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
    while(scanf("%d",&n),n!=-1)
    {
         for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
                  scanf("%d",&d[i][j]);
         int ans=100000,tmp,tmp2,tmp3;
         cnt=0;
         dfs(n-1);
         for(int i=0;i<cnt;i++)
         {
              tmp2=0;
              for(int j=0;j<n;j++)//ÁÐ 
              {
                   tmp=0;
                   for(int k=0;k<n;k++)//ÐÐ 
                   {
                       if(k) 
                       {
                          tmp3=j+pre[i][k-1];
                          if(tmp3>=n) tmp3-=n;
                       } else tmp3=j;
                       tmp+=d[k][tmp3];
                       if(tmp>ans) break;
                   }
                   if(tmp>tmp2) tmp2=tmp;
              }
              if(tmp2<ans) ans=tmp2;
         }
         printf("%d\n",ans);
    }
}
