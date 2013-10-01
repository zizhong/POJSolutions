#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=1010*4,N=1010,inf=0x3ffffff;
int fir[N],e[M],nx[M],len[M],cnt;
int n;
void addedge(int u,int v,int w)
{
     e[cnt]=v,len[cnt]=w,nx[cnt]=fir[u],fir[u]=cnt++;
}
int d[N],st[N],in[N],cc[N];
int SPFA(int s,int ed)
{
     for(int i=1;i<=n;i++) d[i]=inf,in[i]=0,cc[i]=0;
     d[s]=0;
     int top=0;
     for(int i=1;i<=n;i++) if(fir[i]!=-1)
     {
          st[top++]=i;
          in[i]=1;
          cc[i]=1;
     }
     while(top)
     {
          int cur=st[--top];
          in[cur]=0;
          for(int p=fir[cur];p!=-1;p=nx[p])
          {
               if(d[e[p]]>d[cur]+len[p])
               {
                   d[e[p]]=d[cur]+len[p];
                   if(!in[e[p]])
                   {
                        in[e[p]]=1;
                        st[top++]=e[p];
                        if(++cc[e[p]]>n) return -1;
                   }
               }
          }
     }
     //for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
     return abs(d[ed]);
}
struct Tree
{
    int i,h;
    void init(int ii){i=ii;scanf("%d",&h);}  
}tree[N];
bool cmp(const Tree t1,const Tree t2)
{
     return t1.h < t2.h;
}
int main()
{
    int di;
    while(scanf("%d%d",&n,&di),n)
    {
          for(int i=1;i<=n;i++) fir[i]=-1;cnt=0;
          for(int i=1;i<=n;i++) tree[i].init(i); 
          sort(tree+1,tree+1+n,cmp);
          for(int i=1;i<n;i++)
              addedge(min(tree[i].i,tree[i+1].i),max(tree[i].i,tree[i+1].i),di),
              addedge(i+1,i,-1);
          //for(int i=1;i<=n;i++) for(int p=fir[i];p!=-1;p=nx[p]) printf("<%d,%d,%d>\n",i,e[p],len[p]);
          printf("%d\n",SPFA(min(tree[1].i,tree[n].i),max(tree[1].i,tree[n].i)));
    }  
}
