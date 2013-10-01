#include<stdio.h>
#include<string.h>
const int N=300;
int n,m,nv[N],mv[N],g[N][N],r,c,vst[N];
char map[41][11];
int d[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
int inside(int x,int y){return x>=0&&x<r&&y>=0&&y<=c;}
void buildG()
{
     int num[41][11]={0};
     memset(g,0,sizeof(g));
     n=m=0;
     for(int i=0;i<r;i++)
         for(int j=0;j<c;j++)
             if(map[i][j]=='*')
             {
                 if((i+j)&1) num[i][j]=m++;
                 else num[i][j]=n++;
             }
     for(int i=0;i<r;i++)
     {
          for(int j=0;j<c;j++)
          {
              if(map[i][j]=='*')
                  for(int k=0;k<4;k++)
                  {
                          if(inside(i+d[k][0],j+d[k][1])&&map[i+d[k][0]][j+d[k][1]]=='*')
                          {
                                if((i+j)&1) g[num[i+d[k][0]][j+d[k][1]]][num[i][j]]=1;
                                else g[num[i][j]][num[i+d[k][0]][j+d[k][1]]]=1;
                          }
                  }
          }
     }     
}
int dfs(int n_v)
{
    for(int i=0;i<m;i++)
    {
         if(vst[i]==-1&&g[n_v][i]==1)
         {
              vst[i]=1;
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
    int T;
    scanf("%d",&T);
    while(T--)
    {        
        scanf("%d%d",&r,&c);
        getchar();
        for(int i=0;i<r;i++)
                gets(map[i]);        
        buildG();
        memset(nv,-1,sizeof(nv));
        memset(mv,-1,sizeof(mv));
        int ans=0;
        for(int i=0;i<n;i++)
        {
                if(nv[i]==-1)
                for(int j=0;j<m;j++)
                {
                        if(g[i][j]&&mv[j]==-1)
                        {
                             nv[i]=j,mv[j]=i;
                             ans++;
                             break;
                        }
                }
        }               
        for(int i=0;i<n;i++)
        {
                if(nv[i]==-1)
                {
                     memset(vst,-1,sizeof(vst));
                     if(dfs(i)) ans++;
                }
        }
        printf("%d\n",n+m-ans);
    }
}
