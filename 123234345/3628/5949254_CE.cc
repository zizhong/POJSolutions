#include<stdio.h>
const int N=21;
int n,p,ans;
int b[N];
int _min(int a,int b)
{
    return a>b?b:a;
}
void dfs(int i,int w)
{
     if(i>n) return ;
     if(w>=p) 
     {
          ans=_min(ans,w-p);
          return ;
     }
     dfs(i+1,w);
     dfs(i+1,w+b[i+1]);     
}
int main()
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    scanf("%d%d",&n,&p);
    ans=20000000;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    dfs(0,0);
    printf("%d\n",ans);
}
