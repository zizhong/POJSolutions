#include<stdio.h>
const int N=100001;
__int64 sum[N];
int n,q;
struct Seg
{
       int l,r,id;
       __int64 v;
}seg[N*10];
void build(int l,int r,int idx)
{
     seg[idx].l=l;
     seg[idx].r=r;
     seg[idx].v=0;
     seg[idx].id=1;
     if(l==r) return ;
     build(l,(l+r)/2,idx*2);
     build((l+r)/2+1,r,idx*2+1);
}
void modify(int l,int r,int v,int idx)
{
     if(seg[idx].l>r) return ;
     if(seg[idx].r<l) return ;
     if(seg[idx].l==seg[idx].r)
     {
           seg[idx].v+=v;
           return ;
     }
     if(seg[idx].l>=l&&seg[idx].r<=r&&seg[idx].id==1)
     {
           seg[idx].v+=v;
           return ;
     }
     if(seg[idx].id==1)
     {
         seg[idx].id=0;
         seg[idx*2].id=seg[idx*2+1].id=1;
         seg[idx*2].v=seg[idx*2+1].v=seg[idx].v;
     }
     modify(l,r,v,idx*2);
     modify(l,r,v,idx*2+1);
}
__int64 sumseg(int l,int r,int idx)
{
        if(seg[idx].l==seg[idx].r)
              return seg[idx].v;
        if(seg[idx].id) 
            return seg[idx].v*(r-l+1);
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
