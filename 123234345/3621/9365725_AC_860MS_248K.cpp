#include<cstdio>
#include<cstring>
const int N=1024;
const int M=5010;
int fir[N],toV[M],nxt[M],len[M],cnt;
int w[N];
void init()
{
     memset(fir,-1,sizeof(fir));
     cnt=0;
}
void addedge(int a,int b,int t)
{
     toV[cnt]=b,len[cnt]=t,nxt[cnt]=fir[a],fir[a]=cnt++;
}
int n,m;
double wlen(int l,int i,double r)
{
       return l*r-w[i];
}
bool SPFA(double r)
{
     int q[M],head=0,tail=0;
     double dis[N];
     int inq[N],cntin[N];
     for(int i=1;i<=n;i++)
     {
         dis[i]=1e8;
         inq[i]=0;
         cntin[i]=0;
     }    
     dis[1]=0,inq[1]=1,cntin[1]=1;
     q[tail++]=1;
     while(head!=tail)
     {
         int cur=q[head++];
         if(head>=n) head-=n;
         inq[cur]=0;
         for(int p=fir[cur];p!=-1;p=nxt[p])
         {
              if(dis[toV[p]]>dis[cur]+wlen(len[p],cur,r))
              {
                    dis[toV[p]]=dis[cur]+wlen(len[p],cur,r);
                    if(!inq[toV[p]])
                    {
                          inq[toV[p]]=1;
                          q[tail++]=toV[p];
                          if(tail>=n) tail-=n; 
                          if(++cntin[toV[p]]>n) return false;
                    }
              }
         }
     }
     return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&w[i]);
    init();
    for(int i=1;i<=m;i++)
    {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        addedge(a,b,t);
    }
    double l=0,r=1e8;
    while(l+1e-6<r)
    {
        double mid=(l+r)*0.5;
        //printf("%.3f %.3f\n",l,r);
        if(SPFA(mid)) r=mid;
        else l=mid;
    }
    //int ans=(int)(l*1000);
    //printf("%.2f\n",ans/1000.0);
    printf("%.2f\n",l);
    //scanf("%'d");
}
