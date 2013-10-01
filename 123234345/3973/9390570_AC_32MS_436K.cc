#include<cstdio>
#include<cstring>
const int N=128;
int g[N][N];
int xm[N],ym[N],vst[N],na,nb;
int dfs(int x)
{
    for(int y=1;y<=nb;y++) if(g[x][y] && !vst[y])
    {
        vst[y]=1;
        if(ym[y]==-1 || dfs(ym[y]))
        {
             ym[y]=x;
             xm[x]=y;
             return 1; 
        }
    }
    return 0;
}
int max_match()
{
    memset(xm,-1,sizeof(xm));
    memset(ym,-1,sizeof(ym));
    int ans=0;
    for(int i=1;i<=na;i++) if(xm[i]==-1)
        for(int j=1;j<=nb;j++) if(ym[j]==-1&&g[i][j])
        {
             ans++;
             xm[i]=j;
             ym[j]=i;
             break;
        }
    for(int i=1;i<=na;i++) if(xm[i]==-1)
    {
         memset(vst,0,sizeof(vst));
         if(dfs(i)) ans++;
    }
    return ans;             
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
         scanf("%d%d",&nb,&na);
         memset(g,0,sizeof(g));
         for(int i=1;i<=na;i++)
         {
             int k,x;
             scanf("%d",&k);
             while(k--)
             {
                 scanf("%d",&x);
                 g[i][x]=1;
             }
         }
         printf("Case %d: %d\n",tt,na+nb-max_match());
    }
}
