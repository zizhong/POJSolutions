#include<stdio.h>
#include<string.h>
const int N=501,LEN=101;
struct Peo
{
       int h;
       char sex[2],music[LEN],sport[LEN];
}p[N];
int n,m,g[N][N],nv[N],mv[N],vst[N],ii,gi,ni[N],mi[N];
int _abs(int a){return a>0?a:-a;}
int dfs(int u,int level)
{
    for(int i=0;i<m;i++)
    {
         if(vst[i]!=level&&g[u][i]==gi)
         {
              vst[i]=level;
              if(mv[i]==-1||dfs(mv[i],level))
              {
                   mv[i]=u;
                   nv[u]=i;
                   return 1;
              }
         }
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int ns=0;
         n=m=0,gi++;
         scanf("%d",&ns);         
         for(int i=0;i<ns;i++)
         {
              scanf("%d%s%s%s",&p[i].h,p[i].sex,p[i].music,p[i].sport);
              if(p[i].sex[0]=='M') ni[n++]=i;
              else mi[m++]=i;
         }
         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                 Peo v=p[ni[i]],u=p[mi[j]];
                 if(_abs(v.h-u.h)<=40&&!strcmp(v.music,u.music)&&strcmp(v.sport,u.sport))
                     g[i][j]=gi;
            }
         memset(nv,-1,sizeof(nv));
         memset(mv,-1,sizeof(mv));
         int ans=0;
         for(int i=0;i<n;i++)
            if(nv[i]==-1)
            {
                 ii++;
                 if(dfs(i,ii)) ans++;
            }
         printf("%d\n",ns-ans);
    }
}
