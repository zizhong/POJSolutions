#include<stdio.h>
const int N=100001;
int pre[N],kind[N],rank[N];
int find(int x)
{
    if(pre[x]<0) return x;
    int t=pre[x];
    pre[x]=find(t);
    kind[x]^=kind[t];
    return pre[x];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int n,m;
         scanf("%d%d",&n,&m);
         for(int i=1;i<=n;i++)
             pre[i]=-1,kind[i]=0;
         for(int i=1;i<=m;i++)
         {
             char s[8];
             int a,b;
             scanf("%s%d%d",s,&a,&b);
             int x=find(a),y=find(b);
             if(s[0]=='A')
             {
                 if(x==y)
                 {
                       if(kind[a]==kind[b])
                           printf("In the same gang.\n");
                       else printf("In different gangs.\n");
                 }
                 else printf("Not sure yet.\n");
             }
             else
             {
                 if(rank[x]<rank[y])
                 {
                     pre[x]=y;
                     kind[x]=kind[a]^kind[b]^1;
                 }
                 else
                 {
                     pre[y]=x;
                     kind[y]=kind[a]^kind[b]^1;
                     if(rank[x]==rank[y]) rank[x]++;
                 }
             }
         }
    }
}
