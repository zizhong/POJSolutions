#include<iostream>
#include<cstdio>
#include<cstring>
const int N=1010,M=20010+N,inf=0x3fffffff;
int fir[N],e[M],len[M],nx[M],cnt;
int n,m1,m2;
int d[N],in[N],st[N],cc[N],top;
void addedge(int u,int v,int w)
{
     e[cnt]=v,len[cnt]=w,nx[cnt]=fir[u],fir[u]=cnt++;
}
int SPFA()
{
     for(int i=1;i<=n;i++) d[i]=inf,in[i]=0,cc[i]=0;
     d[1]=0,top=0;
     for(int i=1;i<=n;i++) if(fir[i]!=-1)
     {
          st[top++]=i,in[i]=1;
     }
     while(top)
     {
          int cur=st[--top];
          in[cur]=0;
          cc[cur]++;
          if(cc[cur]>n) return -1;
          for(int p=fir[cur];p!=-1;p=nx[p])
          {
                if(d[e[p]]>d[cur]+len[p])
                {     
                     d[e[p]]=d[cur]+len[p];
                     if(!in[e[p]])
                     {
                         in[e[p]]=1;
                         st[top++]=e[p];                     
                     }
                }
          }
     }
     //for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
     for(int i=1;i<=n;i++)
        for(int p=fir[i];p!=-1;p=nx[p])
             if(d[e[p]]>d[i]+len[p]) return -1;
     return d[n]==inf?-2:d[n];
}
int main()
{
    while(scanf("%d%d%d",&n,&m1,&m2)==3)
    {
        for(int i=1;i<=n;i++) fir[i]=-1;
        cnt=0;
        //for(int i=1;i<n;i++) addedge(i+1,i,0);
        for(int i=0;i<m1;i++)
        {
             int a,b,c;
             scanf("%d%d%d",&a,&b,&c);
             addedge(a,b,c);
        }
        for(int i=0;i<m2;i++)
        {
             int a,b,c;
             scanf("%d%d%d",&a,&b,&c);
             addedge(b,a,-c);
        }
        printf("%d\n",SPFA());
    }
}
