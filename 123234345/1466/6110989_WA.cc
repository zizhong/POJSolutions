#include<stdio.h>
#include<string.h>
const int N=500;
char g[N][N];
short nv[N],mv[N],vst[N];
int n;
int dfs(int n_v)
{
    for(int i=0;i<n;i++)
    {
         if(g[n_v][i]&&!vst[i])
         {
              vst[i]=1;
              if(mv[i]==-1||dfs(mv[i]))
              {
                  mv[i]=n_v;
                  nv[n_v]=i;
                  return 1;
              }
         }
    }
    return 0;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         memset(g,0,sizeof(g));
         for(int i=0;i<n;i++)
         {
              int ni=0;
              char s[10];
              scanf("%*s%s",s);
              for(int j=1;s[j]!=')';j++)
                  ni=ni*10+s[j]-'0';
              while(ni--)
              {
                    int x;
                    scanf("%d",&x);
                    if(!g[x][i]) g[i][x]=1;
              }
         }
         int ans=0;
         for(int i=0;i<n;i++)
         {
              if(nv[i]==-1)
              {
                   memset(vst,0,sizeof(vst));
                   if(dfs(i)) ans++;
              }
         }
         printf("%d\n",n-ans);
    }
}
