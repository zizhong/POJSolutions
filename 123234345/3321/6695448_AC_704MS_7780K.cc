#include<stdio.h>
const int N=100005;
struct Node
{
       int to,next;
}b[2*N];
int curnt,adj[N][2],a[N],nums,bg[N],end[N],vst[N],c[N],n;
int lowbit(int x){return x&(-x);}
void modify(int i)
{
     int v=1;
     if(c[i]) v=-1,c[i]=false;
     else c[i]=true;
     for(;i<=n;i+=lowbit(i)) a[i]+=v;
}
int sum(int l,int r)
{
    int ans=0;
    for(int i=r;i>0;i-=lowbit(i)) ans+=a[i];
    for(int i=l;i>0;i-=lowbit(i)) ans-=a[i];
    return ans;
}
void add(int u,int v)
{
     b[curnt].to=v;
     b[curnt].next=-1;
     if(adj[u][0]==-1) adj[u][0]=curnt;
     else b[adj[u][1]].next=curnt;
     adj[u][1]=curnt++;
}
void init()
{
     curnt=0;
     for(int i=1;i<=n;i++)
     {
          adj[i][0]=adj[i][1]=-1;
          a[i]=c[i]=vst[i]=0;
     }
}
void dfs(int now)
{
     vst[now]=1;
     bg[now]=++nums;
     for(int i=adj[now][0];i+1;i=b[i].next)
              if(!vst[b[i].to])
                   dfs(b[i].to);
     end[now]=nums;
     modify(bg[now]);
}
int main()
{
    int m,t=0,x,y;
    while(~scanf("%d",&n))
    {
         init();
         for(int i=1;i<n;i++)
         {
              scanf("%d%d",&x,&y);
              add(x,y),add(y,x);
         }
         nums=0;
         dfs(1);
         scanf("%d",&m);
         while(m--)
         {
              char ch[2];
              scanf("%s%d",ch,&t);
              if(ch[0]=='Q') printf("%d\n",sum(bg[t]-1,end[t]));
              else modify(bg[t]);
         }
    }
}
