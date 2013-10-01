#include<stdio.h>
const int N=100001;
__int64 sum[N];
int n,q;
struct Seg
{
       int l,r;
       __int64 v,sum;
}seg[N*6];
void build(int l,int r,int idx)
{
     seg[idx].l=l;
     seg[idx].r=r;
     seg[idx].v=0;
     seg[idx].sum=0;
     if(l==r) return ;
     build(l,(l+r)/2,idx*2);
     build((l+r)/2+1,r,idx*2+1);
}
void modify(int l,int r,int v,int idx)
{
     if(l<=seg[idx].l&&seg[idx].r<=r)
     {
           seg[idx].v+=v;
           seg[idx].sum+=(__int64)v*(seg[idx].r-seg[idx].l+1);
           return ;
     }
     if(seg[idx].v)
     {
          seg[2*idx].v+=seg[idx].v;
          seg[2*idx+1].v+=seg[idx].v;
          seg[2*idx].sum+=seg[idx].v*(seg[2*idx].r-seg[2*idx].l+1);
          seg[2*idx+1].sum+=seg[idx].v*(seg[2*idx+1].r-seg[2*idx+1].l+1);
          seg[idx].v=0;
     }
     int mid=seg[idx].l+seg[idx].r>>1;
     if(l<=mid) modify(l,r,v,2*idx);
     if(mid+1<=r) modify(l,r,v,2*idx+1);
     seg[idx].sum=seg[2*idx].sum+seg[2*idx+1].sum;
}
__int64 sumseg(int l,int r,int idx)
{
        if(l==seg[idx].l&&seg[idx].r==r)
            return seg[idx].sum;
        if(seg[idx].v)
        {
          seg[2*idx].v+=seg[idx].v;
          seg[2*idx+1].v+=seg[idx].v;
          seg[2*idx].sum+=seg[idx].v*(seg[2*idx].r-seg[2*idx].l+1);
          seg[2*idx+1].sum+=seg[idx].v*(seg[2*idx+1].r-seg[2*idx+1].l+1);
          seg[idx].v=0;
        }
        int mid=seg[idx].l+seg[idx].r>>1;
        if(r<=mid) return sumseg(l,r,idx*2);
        else if(mid+1<=l) return sumseg(l,r,idx*2+1);
        else return sumseg(l,mid,2*idx)+sumseg(mid+1,r,2*idx+1);
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    build(1,n,1);
    char s[2];
    while(q--)
    {
       scanf("%s",s);
       if(s[0]=='C')
       {
           int l,r,v;
           scanf("%d%d%d",&l,&r,&v);
           modify(l,r,v,1);
       }else
       {
           int l,r;
           scanf("%d%d",&l,&r);
           printf("%I64d\n",sumseg(l,r,1)+sum[r]-sum[l-1]);
       }
    }
}
