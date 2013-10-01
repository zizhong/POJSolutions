#include<stdio.h>
#include<string.h>
const int N=30001;
int n,m,pre[N],rank[N];
int root(int x)
{
    int r=x;
    while(pre[r]>=0) r=pre[r];
    while(x!=r)
    {
         int t=pre[x];
         pre[x]=r;
         x=t;
    }
    return r;
}
void Union(int a,int b)
{
    int r1=root(a),r2=root(b);
    if(r1==r2) return ;
    if(rank[r1]>rank[r2]) pre[r2]=r1;
    if(rank[r2]>rank[r1]) pre[r1]=r2;
    if(rank[r1]==rank[r2])
    {
          pre[r2]=r1;
          rank[r1]++;
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
         memset(pre,-1,sizeof(pre));
         memset(rank,0,sizeof(rank));
         for(int i=0;i<m;i++)
         {
              int k,x,y;
              scanf("%d",&k);
              if(k>0) scanf("%d",&x);
              for(int j=0;j<k-1;j++)
              {
                   scanf("%d",&y);
                   Union(x,y);
              }
         }
         int r0=root(0),ans=0;
         for(int i=0;i<n;i++)
           if(root(i)==root(0))
               ans++;
         printf("%d\n",ans);
    }
}
