#include<stdio.h>
const int N=500001;
int n,q;
int d[N];
int _min(int a,int b){return a>b?b:a;}
int _max(int a,int b){return a>b?a:b;}
struct Intv
{
       int l,r,min,max;
}segt[N*3];
void create(int l,int r,int num)
{
     segt[num].l=l;
     segt[num].r=r;
     if(l==r)
     {
             segt[num].min=segt[num].max=d[l];
             return ;
     }
     int mid=l+r>>1;
     create(l,mid,2*num);
     create(mid+1,r,2*num+1);
     segt[num].min=_min(segt[num*2].min,segt[num*2+1].min);
     segt[num].max=_max(segt[num*2].max,segt[num*2+1].max);
     return ;
}
void query(int l,int r,int num,int& max,int& min)
{
    if(segt[num].l==l&&segt[num].r==r)
    {
            max=_max(max,segt[num].max);
            min=_min(min,segt[num].min);
            return ;
    }
    int mid=segt[num].l+segt[num].r>>1;
    if(r<=mid) query(l,r,2*num,max,min);
    else if(l>mid) query(l,r,2*num+1,max,min);
    else
    {
        query(l,mid,2*num,max,min);
        query(mid+1,r,2*num+1,max,min);
    }
}
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
            scanf("%d",&d[i]);
    create(1,n,1);
    while(q--)
    {
         int a,b,min=10000001,max=0;
         scanf("%d%d",&a,&b);
         query(a,b,1,max,min);
         printf("%d\n",max-min);
         
    }
}
