#include<stdio.h>
#include<string.h>
const int N=103;
int min,map[N][N],nv[N],mv[N];
bool vst[N];
int n,m;
int dfs(int n_v)
{
    for(int i=0;i<m;i++)
    {
        if(!vst[i]&&map[n_v][i]==1)
        {
            vst[i]=true;
            if(mv[i]==-1||dfs(mv[i])==1)
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
    int k,a,b;
    while(scanf("%d",&n),n)
    {
         scanf("%d%d",&m,&k);
         memset(map,-1,sizeof(map));
         for(int i=k;i>=1;i--)
         {
              scanf("%d%d%d",&k,&a,&b);
              if(a*b) map[a][b]=1;
         }
         int ans=0;
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         for(int i=0;i<n;i++)
            if(nv[i]==-1)
            {
                memset(vst,0,sizeof(vst));
                if(dfs(i)==1) ans++;
            }
         printf("%d\n",ans);
    }    
}
