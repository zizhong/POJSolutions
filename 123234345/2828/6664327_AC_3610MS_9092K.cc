#include<stdio.h>
const int N=200001;
struct Seg
{
       int l,r,n;
}seg[3*N];
int f[N],n,pos[N],val[N];
void create(int l,int r,int num)
{
     seg[num].l=l;
     seg[num].r=r;
     seg[num].n=r-l+1;
     if(l==r) return ;
     create(l,(l+r)>>1,2*num);
     create(((l+r)>>1)+1,r,2*num+1);
}
void insert(int pos,int p,int num)
{
     seg[num].n--;
     if(seg[num].l==seg[num].r)
     {
           f[seg[num].l]=p;
           return ;
     }
     if(seg[2*num].n>=pos) insert(pos,p,2*num);
     else insert(pos-seg[2*num].n,p,2*num+1);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
         for(int i=1;i<=n;i++) scanf("%d%d",&pos[i],&val[i]);
         create(1,n,1);
         for(int i=n;i>=1;i--)
         {
              insert(pos[i]+1,val[i],1);
         }
         for(int i=1;i<=n;i++) printf("%d%c",f[i],i==n?'\n':' ');
    }
}
