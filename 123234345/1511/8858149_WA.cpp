#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1000010,M=2*N;
const __int64 inf=((__int64)1)<<62;
int n,m;
int num1,nbs1[N],next1[M],ev1[M],ew1[M];//graph_list
int num2,nbs2[N],next2[M],ev2[M],ew2[M];
int len,pos[N],heap[N];//heap
int mark[N];
__int64 dist1[N];//dijkstra
void update(__int64 dist[],int r)
{
     int q=pos[r],p=q<<1;
     while(p && dist[heap[p]]>dist[r])
     {
         pos[heap[p]]=q;
         heap[q]=heap[p];
         q=p;
         p=q>>1;
     }
     heap[q]=r;
     pos[r]=q;
}
int getmin(__int64 dist[])
{
    int ret=heap[1];
    int p=1,q=2;
    int r=heap[len--];
    while(q<=len)
    {
        if(q<len && dist[heap[q+1]]<dist[heap[q]]) q++;
        if(dist[heap[q]]<dist[r])
        {
             pos[heap[q]]=p;
             heap[p]=heap[q];
             p=q;
             q=p<<1;
        }else break;
    }
    heap[p]=r;
    pos[r]=p;
    return ret;
}
__int64  dijkstra(int src,__int64 dist[],int nbs[],int next[],int ev[],int ew[])
{
     for(int i=1;i<=n;i++)
     {
          dist[i]=inf;
          mark[i]=0;
          pos[i]=0;
     }
     dist[src]=0,len=1,heap[1]=src,pos[src]=1,dist[src]=0,mark[src]=1;
     while(1)
     {
           if(len==0) break;
           int u=getmin(dist);
           mark[u]=1;
           for(int j=nbs[u];j;j=next[j])
           {
                 int v=ev[j];
                 if(!mark[v] && dist[u]+ew[j]<dist[v])
                 {
                      if(pos[v]==0)
                      {
                          heap[++len]=v;
                          pos[v]=len;
                      }
                      dist[v]=dist[u]+ew[j];
                      update(dist,v);
                 }
           }
     }
     __int64 ans=0;
     for(int i=1;i<=n;i++)
         ans+=dist[i];
     return ans;
}
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
         scanf("%d%d",&n,&m);
         num1=num2=0;
         int ans=0;
         for(int i=1;i<=n;i++) nbs1[i]=nbs2[i]=0;
         while(m--)
         {
              int u,v,w;
              scanf("%d%d%d",&u,&v,&w);
              next1[++num1]=nbs1[u];
              nbs1[u]=num1;
              ev1[num1]=v,ew1[num1]=w;
              
              next2[++num2]=nbs2[v];
              nbs2[v]=num2;
              ev2[num2]=u,ew2[num1]=w;
         }
         
         cout<<dijkstra(1,dist1,nbs1,next1,ev1,ew1) +
                        dijkstra(1,dist1,nbs2,next2,ev2,ew2)<<endl;

    }
}


