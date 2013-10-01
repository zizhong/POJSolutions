#include<stdio.h>
#include<string.h>
const int N=1010;
int w[N];
int fir[N],e[N*2],nxt[N*2],nv;
void init()
{
     nv=0;
     memset(fir,-1,sizeof(fir));
}
void addedge(int u,int v)
{
     e[nv]=v;
     nxt[nv]=fir[u];
     fir[u]=nv++;
}
void insert(int u,int v)
{
     addedge(u,v);
     addedge(v,u);
}

int vst[N];
int d[N],fa[N];
void dfs(int x)
{
     vst[x]=1;
     for(int v=fir[x];v!=-1;v=nxt[v])
     {
           if(vst[e[v]]==0)
           {
                vst[e[v]]=1;
                d[x]++;
                fa[e[v]]=x;
                dfs(e[v]);
           }           
     }
}
int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r),n)
    {
         for(int i=1;i<=n;i++)
              scanf("%d",&w[i]);
         init();
         for(int i=1;i<n;i++)
         {
             int u,v;
             scanf("%d%d",&u,&v);
             insert(u,v);
         }
         
         memset(vst,0,sizeof(vst));
         memset(d,0,sizeof(d));
         fa[r]=0;
         dfs(r);
         
         int ans=0;
         for(int i=n;i>=1;i--)
         {
              int mi=-1;
              for(int j=1;j<=n;j++) if(d[j]==0&&(mi==-1||w[mi]>w[j]))
                    mi=j;
              ans+=w[mi]*i;
              d[mi]=-1;
              d[fa[mi]]--;
         }
         printf("%d\n",ans);
    }
}
