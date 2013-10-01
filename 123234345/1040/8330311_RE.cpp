#include<stdio.h>
#include<stdlib.h>
const int N=50;
int n,m,d;
struct Ord{int x,y,num;}ord[N];
int cmp(const void *a,const void *b)
{
    Ord *p1=(Ord *)a;
    Ord *p2=(Ord *)b;
    return p1->x - p2->x?p1->x - p2->x:p1->y - p2->y;
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
         p[i]+=ord[st].num;
         if(p[i]>n) flag=1;
    }
    if(!flag)
    {
          dfs(st+1,ans1+val[st]);
    }
    for(int i=ord[st].x+1;i<=ord[st].y;i++)
    {
         p[i]-=ord[st].num;
    }
    if(ans1+max[st+1]<=ans) return ;
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
         ans=0;
         max[d]=0;
         for(int i=d-1;i>=0;i--)
              val[i]=(ord[i].y-ord[i].x)*ord[i].num,max[i]=max[i+1]+val[i];
         dfs(0,0);
         printf("%d\n",ans);
    }
}
