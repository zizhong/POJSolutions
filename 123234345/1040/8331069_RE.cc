#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=50;
int n,m,d;
struct Ord{int x,y,num;}ord[N];
int cmp(const void *a,const void *b)
{
    Ord *p1=(Ord *)a;
    Ord *p2=(Ord *)b;
    return (p2->num*(p2->y-p2->x)) - (p1->num*(p1->y-p1->x));
}
int ans=0;
int p[N],val[N],max[N];
void dfs(int st,int ans1)
{
     //printf("%d %d\n",st,ans1);
    if(st==n)
    {
        if(ans<ans1) ans=ans1;
        return ;
    }
    if(ans1+max[st]<=ans) return ;
    int flag=0;
    for(int i=ord[st].x+1;i<=ord[st].y;i++)
    {
         if(p[i]+ord[st].num>n) flag=1;
    }
    if(!flag)
    {
          
        for(int i=ord[st].x+1;i<=ord[st].y;i++)
              p[i]+=ord[st].num;
        ans1+=val[st];
          dfs(st+1,ans1);
        ans1-=val[st];
        for(int i=ord[st].x+1;i<=ord[st].y;i++)
              p[i]-=ord[st].num;
    }
    dfs(st+1,ans1);
    return ;    
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%d",&n,&m,&d)==3&&(n+m+d))
    {
         for(int i=0;i<d;i++)
         {
              scanf("%d%d%d",&ord[i].x,&ord[i].y,&ord[i].num);
              if(ord[i].x>ord[i].y) {int t=ord[i].x;ord[i].x=ord[i].y;ord[i].y=t;}              
         }
         qsort(ord,d,sizeof(ord[0]),cmp);
         memset(p,0,sizeof(p));
         ans=0;
         max[d]=0;
         for(int i=d-1;i>=0;i--)
              val[i]=(ord[i].y-ord[i].x)*ord[i].num,max[i]=max[i+1]+val[i];
         dfs(0,0);
         printf("%d\n",ans);
    }
}
