#include<cstdio>
#include<cstring>
const int N=1024,M=10010;
int fir[N],vv[M],nxt[M],cnt;
void init()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
void addedge(int u,int v)
{
     vv[cnt]=v,nxt[cnt]=fir[u],fir[u]=cnt++;
}
int c,n,m,cow[128],nn[1024];
void bfs(int x)
{
     int vst[N]={0},q[N],head=0,tail=0;
     vst[x]=1;
     q[tail++]=x;
     while(head<tail)
     {
          int cur=q[head++];
          for(int i=fir[cur];i!=-1;i=nxt[i])
          {
               int v=vv[i];
               if(vst[v]) continue;
               vst[v]=1;
               q[tail++]=v;
          }
     }
     for(int i=1;i<=n;i++) nn[i]+=vst[i];
}
int main()
{
    init();
    scanf("%d%d%d",&c,&n,&m);
    for(int i=0;i<c;i++)
    {
         scanf("%d",&cow[i]);
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    for(int i=0;i<c;i++)
    {
        bfs(cow[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(nn[i]==c) ans++;
    printf("%d\n",ans);
}
