#include<cstdio>
#include<cstring>
using namespace std;
const int inf=0x3fffffff;
int d[1024],pre[1024];
bool g[1024][1024],vst[1024];
void print(int x)
{
     if(pre[x]>0) print(pre[x]);
     printf("%d\n",x);
}
int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
         int u,v;
         scanf("%d%d",&u,&v);
         g[u][v]=true;
    }
    for(int i=1;i<=n;i++)
    {
         vst[i]=false;
         pre[i]=1;
         d[i]=g[1][i]?1:inf;
    }
    vst[1]=true;
    d[1]=0;
    pre[1]=-1;
    while(true)
    {
         int min=inf,tail=-1;
         for(int i=1;i<=n;i++) if(vst[i]==false && min>d[i])
              min=d[i],tail=i;
         if(tail==-1) break;
         vst[tail]=true;
         for(int i=1;i<=n;i++) if(vst[i]==false && g[tail][i] && d[tail]+1<d[i])
               d[i]=d[tail]+1,pre[i]=tail;
    }
    if(vst[n]==false) puts("-1");
    else
    {   
        printf("%d\n",d[n]+1);     
        print(n);
    }
}
