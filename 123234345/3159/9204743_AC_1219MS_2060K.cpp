#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=150010,N=30010,inf=0x3ffffff;
int fir[N],e[M],nx[M],len[M],cnt;
int n,m;
void addedge(int u,int v,int w)
{
     e[cnt]=v,len[cnt]=w,nx[cnt]=fir[u],fir[u]=cnt++;
}
int d[N],st[N],in[N];
void SPFA()
{
     for(int i=1;i<=n;i++) d[i]=inf,in[i]=0;
     d[1]=0;
     int top=0;
     for(int i=1;i<=n;i++) if(fir[i]!=-1)
     {
          st[top++]=i;
          in[i]=1;
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
                   }
               }
          }
     }
}
int myInt()
{
    char c;
    while((c=getchar())<'0' || c>'9') ;
    int x=c-'0';
    while((c=getchar())>='0' && c<='9') x=x*10+c-'0';
    return x;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
         for(int i=1;i<=n;i++) fir[i]=-1;
         cnt=0;
         for(int i=0;i<m;i++)
         {
            int a,b,c;
            a=myInt(),b=myInt(),c=myInt();
            addedge(a,b,c);
         }
         SPFA();
         printf("%d\n",d[n]);
         
    }
}
