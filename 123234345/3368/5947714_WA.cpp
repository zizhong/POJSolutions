#include<stdio.h>
const int N=100001;
int d[N];
struct Intv
{
      int l,r,vl,vr,nl,nr,n;
}segt[3*N];
int _max(int a,int b)
{
    return a>b?a:b;
}
int _min(int a,int b)
{
    return a>b?b:a;
}
void display(int num)
{
     printf("%3d,l=%3d,r=%3d,vl=%3d,vr=%3d,n=%3d,nl=%3d,nr=%3d\n",num,segt[num].l,segt[num].r,segt[num].vl,segt[num].vr,segt[num].n,segt[num].nl,segt[num].nr);
}
void create(int l,int r,int num)
{
     segt[num].l=l,
     segt[num].r=r,
     segt[num].vl=d[l];
     segt[num].vr=d[r-1];
     if(l+1==r)
     {
          segt[num].n=segt[num].nr=segt[num].nl=1;
          return ;
     }
     int mid=(l+r)>>1;
     create(l,mid,2*num);
     create(mid,r,2*num+1);
     int max=_max(segt[num*2].n,segt[2*num+1].n);
     if(d[mid-1]==d[mid]) max=_max(segt[2*num].nr+segt[2*num+1].nl,max);
     segt[num].n=max;
     segt[num].nl=segt[2*num].nl;
     segt[num].nr=segt[2*num+1].nr;
     if(segt[2*num].vl==segt[2*num].vr&&(segt[num*2].vr==segt[num*2+1].vl)) segt[num].nl+=segt[2*num+1].nl;
     if(segt[2*num+1].vl==segt[2*num+1].vr&&(segt[num*2].vr==segt[num*2+1].vl)) segt[num].nr+=segt[2*num].nr;
}
int query(int l,int r,int num)
{
    //display(num);
    if(segt[num].l==l&&segt[num].r==r) return segt[num].n;
    int mid=(segt[num].l+segt[num].r)>>1;
    if(r<=mid) return query(l,r,2*num);
    if(mid<=l) return query(l,r,2*num+1);
    int n1=query(l,mid,2*num),n2=query(mid,r,2*num+1);
    int max=_max(n1,n2);
    if(segt[2*num].vr==segt[2*num+1].vl)
    {
          int r1=_min(segt[2*num].vr,mid-l),
              l1=_min(segt[2*num+1].vl,r-mid);
          max=_max(max,r1+l1);
    }
    return max;    
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        create(1,n+1,1);
        int a,b;
        for(int i=0;i<m;i++)
        {
             scanf("%d%d",&a,&b);
             int p;
             printf("%d\n",query(a,b+1,1));
        }
    }
} 
