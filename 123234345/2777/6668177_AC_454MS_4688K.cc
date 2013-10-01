#include<stdio.h>
const int N=100001,T=32;
int n,o,t,c,flag,f[T];
struct Node
{
       int l,r,t,mid;
}seg[3*N];
void create(int l,int r,int num)
{
     seg[num].l=l;
     seg[num].r=r;
     seg[num].mid=(l+r)>>1;
     seg[num].t=1;
     if(l==r) return ;
     create(l,l+r>>1,num<<1);
     create((l+r>>1)+1,r,(num<<1)+1);
}
void insert(int l,int r,int num)
{
     if((seg[num].l==l&&seg[num].r==r))
     {
           seg[num].t=c;
           return ;
     }
     int x=seg[num].t;
     if(x) seg[2*num].t=seg[num*2+1].t=x,seg[num].t=0;
     if(seg[num].mid>=r) insert(l,r,num<<1);
     else if(seg[num].mid<l) insert(l,r,2*num+1);
     else 
     insert(l,seg[num].mid,2*num),
     insert(seg[num].mid+1,r,2*num+1);
}
void xplor(int l,int r,int num)
{
     if(seg[num].t) {f[seg[num].t]=flag;return ;}
     if(seg[num].mid>=r) xplor(l,r,2*num);
     else if(seg[num].mid<l) xplor(l,r,2*num+1);
     else 
     xplor(l,seg[num].mid,2*num),
     xplor(seg[num].mid+1,r,2*num+1);     
}
int main()
{
    scanf("%d%d%d",&n,&t,&o);
    create(1,n,1);
    while(o--)
    {
        char s[2];
        int a,b;
        scanf("%s",s);
        if(s[0]=='C')
        {
             scanf("%d%d%d",&a,&b,&c);
             insert(a,b,1);
        }else
        {
             flag++;
             int ans=0;
             scanf("%d%d",&a,&b);
             xplor(a,b,1);
             for(int i=1;i<=t;i++) if(f[i]==flag)
                 ans++;
             printf("%d\n",ans);
        }
    }
}
