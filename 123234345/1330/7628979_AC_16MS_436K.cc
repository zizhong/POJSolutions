#include<stdio.h>
const int N=10001;
int pre[N];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         scanf("%d",&n);
         for(int i=1;i<=n;i++) pre[i]=0;
         for(int i=1;i<n;i++)
         {
             int x,y;
             scanf("%d%d",&x,&y);
             pre[y]=x;
         }
         int u,v;
         scanf("%d%d",&u,&v);
         int path[N]={0};
         int x=u;
         while(pre[x])
         {
               path[x]=1;
               x=pre[x];
         }
         path[x]=1;
         x=v;
         while(path[x]==0)
         {
              x=pre[x];
         }
         printf("%d\n",x);
    }
}
