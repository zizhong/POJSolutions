#include<cstdio>
#include<cstring>
const int  N=64,d[][2]={{-1,0},{1,0},{0,1},{0,-1}};
int g[N][N];
char map[N][N];
int n,m;
void dfs(int x,int y)
{
     map[x][y]='.';
     g[x][y]=1;
     for(int k=0;k<4;k++)
     {
         int nx=x+d[k][0],ny=y+d[k][1];
         if(nx>=0 && nx<n && ny>=0 && ny<m && map[nx][ny]=='*')
              dfs(nx,ny);
     }
}

int mv[N],nv[N],vst[N];
int dfs(int n_v)
{
    for(int i=0;i<m;i++) if(vst[i]==-1 && g[n_v][i]==1)
    {
         vst[i]=1;
         if(mv[i]==-1 || dfs(mv[i])==1)
         {
              mv[i]=n_v,nv[n_v]=i;
              return 1;
         }
    }
    return 0;
}
int maxmatch()
{
    memset(nv,-1,sizeof(nv));
    memset(mv,-1,sizeof(mv));
    int ret=0;
    for(int i=0;i<n;i++) if(nv[i]==-1)
        for(int j=0;j<m;j++) if(g[i][j]&&mv[j]==-1)
        {
            nv[i]=j,mv[j]=i;
            ret++;
            break;
        }
    for(int i=0;i<n;i++) if(nv[i]==-1)
    {
         memset(vst,-1,sizeof(vst));
         if(dfs(i)) ret++;
    }
    return ret;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) 
         scanf("%s",map[i]);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) if(map[i][j]=='*')
        {
              memset(g,0,sizeof(g));
              dfs(i,j);
              ans+=maxmatch();
        }
    printf("%d\n",ans);
}
