#include<stdio.h>
#include<stdlib.h>
const int N=22;
int n,m,d;
struct Ord{int x,y,num;}ord[N];
int cmp(const void *a,const void *b)
{
    Ord *p1=(Ord *)a;
    Ord *p2=(Ord *)b;
    return p1->x - p2->x?p1->x - p2->x:p1->y - p2->y;
}
bool ok(int k)
{
    int p[8]={0};
    for(int i=0;i<d;i++)
    {
        if(k&(1<<i))
        {
             for(int j=ord[i].x+1;j<=ord[i].y;j++)
             {                   
                   p[j]+=ord[i].num;
                   if(p[j]>n) return false;
             }
        }
    }
    return true;
}
int cal(int k)
{
    int ans=0;
    for(int i=0;i<d;i++)
         if(k&(1<<i))
             ans+=(ord[i].y-ord[i].x)*ord[i].num;
    return ans;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&d),n+m+d)
    {
         for(int i=0;i<d;i++)
         {
              scanf("%d%d%d",&ord[i].x,&ord[i].y,&ord[i].num);
              if(ord[i].x>ord[i].y) {int t=ord[i].x;ord[i].x=ord[i].y;ord[i].y=t;}
              //qsort(ord,d,sizeof(ord[0]),cmp);
         }
         int ans=0;
         for(int k=1;k<(1<<d);k++)
         {
              int tmp=0;
              if(ok(k)) tmp=cal(k);
              if(tmp>ans) ans=tmp;                  
         }
         printf("%d\n",ans);
    }
}
