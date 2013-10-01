#include<stdio.h>
#include<string.h>
const int N=500;
short g[N][N],nv[N],mv[N],vst[N];
int n,k,a,b;
int dfs(int n_v,int level)
{
    for(int i=0;i<n;i++)
    {
         if(vst[i]!=level&&g[n_v][i])
         {
               vst[i]=level;
               if(mv[i]==-1||dfs(mv[i],level))
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
    scanf("%d%d",&n,&k);
    while(k--)
       scanf("%d%d",&a,&b),g[a-1][b-1]=1;
    memset(nv,-1,sizeof(nv));
    memset(mv,-1,sizeof(mv));
    int ans=0;
    for(int i=0;i<n;i++)
        if(nv[i]==-1)
            if(dfs(i,i+1)) ans++;
    printf("%d\n",ans);
    //scanf("%d",&n);
}
