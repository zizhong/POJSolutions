#include<stdio.h>
#include<string.h>
const int M=7*12,N=301;
int g[N][M],n,nv[N],mv[M],vst[N];
int dfs(int n_v,int level)
{
    for(int i=0;i<M;i++)
    {
         if(vst[i]!=level&&g[n_v][i])
         {
              vst[i]=level;
              if(mv[i]==-1||dfs(i,level))
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
    int ii=0;
    while(scanf("%d",&n)!=EOF)
    {
         int a,b,ni;
         memset(g,0,sizeof(g));
         for(int i=0;i<n;i++)
         {
              scanf("%d",&ni);
              while(ni--)
              {
                   scanf("%d%d",&a,&b);
                   g[i][(a-1)*12+b-1]=1;                   
              }
         }
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         int max=0;
         for(int i=0;i<n;i++)
         {
             if(nv[i]==-1)
             {
                  ii++;
                  if(dfs(i,ii)) max++;
             }
         }
         printf("%d\n",max);
    }
}
