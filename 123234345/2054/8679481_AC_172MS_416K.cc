#include <stdio.h>
const int N = 1002;
int c[N],sum[N],parent[N],count[N],pre[N],next[N];
char used[N];
int n,r,ans;
double k,max;
int main()
{
 int i,u,v;
 while (scanf("%d%d",&n,&r), n )
 {
  for (i=1;i<=n;i++)
  {
   scanf("%d",&c[i]);
   sum[i]=c[i];
   count[i]=1;
   pre[i]=next[i]=0;
   used[i]=0;
  }
  for (i=1;i<n;i++)
  {
   scanf("%d%d",&u,&v);
   parent[v]=u;
  }
  used[r]=1;
  for (i=1;i<n;i++)
  {
   max=0;
   v=-1;
   for (u=1;u<=n;u++)
   {
    if (!used[u])
    {
     k=1.0*sum[u]/count[u];
     if (max<k)
     {
      max=k;
      v=u;
     }
    }
   }
   u=parent[v];
   while (pre[u])
   {
    u=pre[u];
   }
   sum[u]=sum[u]+sum[v];
   count[u]=count[u]+count[v];
   u=parent[v];
   while (next[u])
   {
    u=next[u];
   }
   next[u]=v;
   pre[v]=u;
   used[v]=1;
  }
  i=1;
  ans=0;
  while (next[r])
  {
   ans=ans+i*c[r];
   i++;
   r=next[r];
  }
  ans=ans+i*c[r];
  printf("%d\n",ans);
 }
 
 return 0;
} 
