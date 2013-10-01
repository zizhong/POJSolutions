#include<stdio.h>
int a[101][101];
int dfs(int i,int j)
{
    int x=a[i][j];
    a[i][j]=0;
    int ans=1;
    if(a[i-1][j]==x) ans+=dfs(i-1,j);
    if(a[i][j-1]==x) ans+=dfs(i,j-1);
    if(a[i+1][j]==x) ans+=dfs(i+1,j);
    if(a[i][j+1]==x) ans+=dfs(i,j+1);
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         for(int i=1;i<=n;i++)
             for(int j=1;j<=n;j++)
                 a[i][j]=n;
         for(int i=1;i<n;i++)
         {
              for(int j=1;j<=n;j++)
              {
                      int x,y;
                      scanf("%d%d",&x,&y);
                      a[x][y]=i;
              }              
         }
         int vst[101]={1};
         int flag=1;
         for(int i=1;i<=n&&flag;i++)
         {
              for(int j=1;j<=n&&flag;j++)
              {
                   if(vst[a[i][j]]==0)
                   {
                        vst[a[i][j]]=1;
                        if(dfs(i,j)-n) flag=0;
                   }
              }
         }
         if(flag) puts("good");
         else puts("wrong");         
    }
}
