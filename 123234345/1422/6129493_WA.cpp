#include<stdio.h>
#include<string.h>
const int V=121;
int nv,ne,map[V][V];
int g[V][V],vst[V],lanx[V],lany[V],x,y,ans;
void init()
{
     int xi,yi;
     ans=0;
     memset(map,0,sizeof(map));
     scanf("%d%d",&nv,&ne);
     while(ne--)
         scanf("%d%d",&xi,&yi),map[xi][yi]=1;     
}
void buildG()
{
     for(int k=1;k<=nv;k++)
        for(int i=1;i<=nv;i++)
            for(int j=1;j<=nv;j++)
               if(map[i][k]&map[k][j]) map[i][j]=1;
     memset(g,0,sizeof(g));
     x=y=0;
     int numv[V]={0},bin[V]={0};
     for(int i=1;i<=nv;i++)
     {
          if(!bin[i])
          {
               numv[i]=x++;
               bin[i]=2;
               for(int j=1;j<=nv;j++)
                  if(map[i][j]&&!bin[j]) bin[j]=1,numv[j]=y++;
          }
     }
     int nx[V]={0},ny[V]={0};
     for(int i=1;i<=nv;i++)
         if(bin[i]==1) ny[numv[i]]=i;
         else nx[numv[i]]=i;
     for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
          if(map[nx[i]][ny[j]]) g[i][j]=1;
          else if(map[nx[j]][ny[i]]) g[j][i]=1;
     /*
     puts("G:");   
     for(int i=0;i<x;i++,puts(""))
         for(int j=0;j<y;printf("%d",g[i][j]),j++);
     puts("");*/
}
void Greedy()
{
     memset(lanx,-1,sizeof(lanx));
     memset(lany,-1,sizeof(lany));
     for(int i=0;i<x;i++)
        for(int j=0;j<y&&(lanx[i]==-1);j++)
           if(g[i][j]&&lany[j]==-1) lanx[i]=j,lany[j]=i,ans++;
}
int dfs(int v,int level)
{
     for(int u=0;u<y;u++)
         if(vst[u]!=level&&g[v][u])
         {
              vst[u]=level;
              if(lany[u]==-1||dfs(lany[u],level))
              {
                   lany[u]=v;
                   lanx[v]=u;
                   return 1;
              }
         }
     return 0;
}
void Hungary()
{
     memset(vst,0,sizeof(vst));
     for(int i=0;i<x;i++)
        if(lanx[i]==-1)
        {
             if(dfs(i,i+1)) ans++;
        }
     printf("%d\n",ans);
}
void Sol()
{
     buildG();
     Greedy();
     Hungary();
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         init();
         Sol();         
    }
    return 0;
}
