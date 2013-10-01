#include<stdio.h>
const int N=50010*2;
struct Node
{
       int v;
       Node *next;
}g[N],*e[N];
int f[N],nn;
void insert(int u,int v)
{
     Node *p=&g[nn++];
     p->v=v;
     p->next=e[u];
     e[u]=p;
}
int n1,n2,d;
int dfs(int x)
{
    if(f[x]!=-1) return f[x];
    int res=0;
    for(Node *p=e[x];p;p=p->next)
    {
          if(x<=n1&&p->v<=n1||x>n1&&p->v>n1)
          {
               if(res<dfs(p->v))
                     res=f[p->v];
          }
          else
          {
              if(res<dfs(p->v)+1)
                  res=f[p->v]+1;
          }
    }
    f[x]=res;
    return res;
}
int getInt()
{
    char c;
    int x=0;
    while(!((c=getchar())>='0'&&c<='9')) ;
    x=c-'0';
    while((c=getchar())>='0'&&c<='9') x=x*10+c-'0';
    return x;
}
int main()
{
    
    while(scanf("%d%d%d",&n1,&n2,&d),n1||n2||d)
    {
         for(int i=1;i<=n1+n2;i++)
              e[i]=NULL,f[i]=-1;
         nn=0;
         for(int i=0;i<d;i++)
         {
             int u,v;
             u=getInt(),
             v=getInt();
             insert(u,v);
         }
         int ans1=0;
         for(int i=1;i<=n1;i++)
         {
              if(f[i]==-1) f[i]=dfs(i);
              if(ans1<f[i]) ans1=f[i];
         }
         int ans2=0;
         for(int i=n1+1;i<=n2+n1;i++)
         {
             if(f[i]==-1) dfs(i);
             if(ans2<f[i]) ans2=f[i];
         }
         int ans=0;
         ans=ans1>ans2?ans1:ans2;
         if(ans1==ans2) ans++;
         printf("%d\n",ans+2);
    }
}
