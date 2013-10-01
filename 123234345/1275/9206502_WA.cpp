#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int M=32*4,N=32,inf=0x3fffffff;
int fir[N],e[M],nx[M],len[M],cnt;
void addedge(int u,int v,int w)
{
     e[cnt]=v,len[cnt]=w,nx[cnt]=fir[u],fir[u]=cnt++;
}
int d[N],st[N],in[N],cc[N];
bool SPFA(int src,int n)
{
     for(int i=0;i<n;i++) d[i]=inf,in[i]=0,cc[i]=0;
     d[src]=0;
     int top=0;
     for(int i=0;i<n;i++) if(fir[i]!=-1)
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
               if(d[e[p]]<d[cur]+len[p])
               {
                   d[e[p]]=d[cur]+len[p];
                   if(!in[e[p]])
                   {
                        in[e[p]]=1;
                        st[top++]=e[p];
                        if(++cc[e[p]]>n) return false;
                   }
               }
          }
     }
     return true;
}
void init()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
int r[32],t[32];
bool ok(int x)
{
     init();     
     for(int i=0;i<24;i++)
     {
          addedge(i,i+1,0);
          addedge(i+1,i,-t[i]);
     }
     for(int i=1;i<=24;i++)
     {
          i<=7?addedge(i+16,i,r[i]-x):addedge(i-8,i,r[i]);
     }
     addedge(0,24,x);
     return SPFA(0,25);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int sumN=0,sumP=0;
         for(int i=0;i<24;i++)
         {
              scanf("%d",&r[i]);
              sumN+=r[i];
              t[i]=0;
         }
         scanf("%d",&sumP);
         for(int i=0;i<sumP;i++)
         {
              int x;
              scanf("%d",&x);
              ++t[x];
         }
         if(sumN==0) {puts("0");continue;}
         if(!ok(sumP)) {puts("No Solution");continue;}
         int l=0,r=sumP;
         while(l+1<r)
         {
              int mid=l+r>>1;
              if(ok(mid)) r=mid;
              else l=mid;
         }
         printf("%d\n",r);
    }
}
