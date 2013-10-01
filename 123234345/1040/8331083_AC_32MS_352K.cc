#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct Ord{int x,y,num,val;}ord[23];
int p[8];
int L,m,n,sum,ans;
bool cmp(const Ord&a,const Ord &b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
void dfs(int k,int lm,int ans1,int left)
{
     if(k>=n)
     {
             if(ans1>ans) ans=ans1;
             return ;
     }
     if(ans1+left<=ans) return ;
     if(k>0)
     for(int i=ord[k-1].x+1;i<=ord[k].x;i++) lm+=p[i];
     left-=ord[k].val;
     if(lm>=ord[k].num)
     {
           p[ord[k].y]+=ord[k].num;
           dfs(k+1,lm-ord[k].num,ans1+ord[k].val,left);
           p[ord[k].y]-=ord[k].num;
     }
     dfs(k+1,lm,ans1,left);
}
int main()
{
    while(scanf("%d%d%d",&L,&m,&n),L|m|n)
    {
          ans=sum=0;
          for(int i=0;i<n;i++)
          {
               scanf("%d%d%d",&ord[i].x,&ord[i].y,&ord[i].num);
               ord[i].val=(ord[i].y-ord[i].x)*ord[i].num;
               sum+=ord[i].val;
          }
          sort(ord,ord+n,cmp);
          memset(p,0,sizeof(p));
          dfs(0,L,0,sum);
          printf("%d\n",ans);
    }
}
