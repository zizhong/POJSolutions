#include<stdio.h>
#include<stdlib.h>
const int N=101;
struct Node {int y,x1,x2;}wall[N];
struct Node2{int i,v;}d[N];
int cmp(const void *a,const void *b)
{
    return ((Node2 *)b)->v - ((Node2 *)a)->v;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n,k;
         scanf("%d%d",&n,&k);
         for(int i=0;i<n;i++)
         {
             scanf("%d%d%d%d",&wall[i].x1,&wall[i].y,&wall[i].x2,&wall[i].y);
             if(wall[i].x1>wall[i].x2){int t=wall[i].x1;wall[i].x1=wall[i].x2;wall[i].x2=wall[i].x1;}
         }
         int v[N]={0};
         int ans=0;
         for(int j=0;j<N;j++)
         {
             int sum=0,nn=0;
             for(int i=0;i<n;i++)
             {
                 if(!v[i]&&wall[i].x1<=j&&j<=wall[i].x2)
                      sum++,d[nn].i=i,d[nn].v=wall[i].x2,nn++;
             }
             if(sum<k) continue;
             ans+=sum-k;
             qsort(d,nn,sizeof(d[0]),cmp);
             for(int i=0;i<sum-k;i++)
                 v[d[i].i]=1;
         }
         printf("%d\n",ans);
    }
}
