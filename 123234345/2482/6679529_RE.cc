#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N=40000,M=10001;
struct SEG
{
       int l,r,val,add;
       int mid;
}tt[N];
struct star
{
       int x,y,val;
}hh[M];
int pos[M],n,m,H,W;
int cmp(const void *a,const void *b)
{
    star *p1=(star *)a;
    star *p2=(star *)b;
    return p1->y - p2->y;
}
int cmp2(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int Bin(__int64 x)
{
    int lo=0,hi=m-1;
    while(lo<=hi)
    {
          int mid=lo+hi>>1;
          if(pos[mid]<x) lo=mid+1;
          else hi=mid-1;
    }
}
void build(int l,int r,int idx)
{
     tt[idx].l=l;
     tt[idx].r=r;
     tt[idx].mid=l+r>>1;
     tt[idx].add=tt[idx].val=0;
     if(l==r) return ;
     build(l,tt[idx].mid,idx<<1);
     build(tt[idx].mid+1,r,idx<<1|1);
}
void update(int l,int r,int add,int num)
{
     if(l<=tt[num].l&&r>=tt[num].r)
     {
           tt[num].add+=add;
           tt[num].val+=add;
           return ;
     }
     if(tt[num].add)
     {
           tt[num*2].add+=tt[num].add;
           tt[num*2].val+=tt[num].add;
           tt[num*2+1].add+=tt[num].add;
           tt[num*2+1].val+=tt[num].add;
           tt[num].add=0;
     }
     if(l<=tt[num].mid) update(l,r,add,2*num);
     if(tt[num].mid<r) update(l,r,add,2*num+1);
     tt[num].val=tt[2*num+1].val>tt[2*num].val?tt[2*num+1].val:tt[2*num].val;
}
int main()
{
    while(scanf("%d%d%d",&n,&W,&H)!=EOF)
    {
         for(int i=0;i<n;i++)
         {
               scanf("%d%d%d",&hh[i].x,&hh[i].y,&hh[i].val);
               pos[i]=hh[i].x;
         }
         qsort(hh,n,sizeof(hh[0]),cmp);
         qsort(pos,n,sizeof(pos[0]),cmp2);
         m=0;
         for(int i=0;i<n;i++)
         {
               if(i==0||pos[i]!=pos[i-1]) pos[m++]=pos[i];
         }
         build(0,m-1,1);
         int start=0,end=0;
         int ans=0;
         for(int i=0;i<n;i++)
         {
              if(i&&hh[i].y==hh[i-1].y) continue;
              for(int j=start;j<i;j++)
              {
                     update(Bin(hh[j].x),Bin(hh[j].x+W)-1,-hh[j].val,1);
              }
              start=i;
              int lo=i,hi=n-1;
              __int64 buf =(__int64)hh[i].y+H;
              while(lo<=hi)
              {
                    int mid =(lo+hi)>>1;
                    if(hh[mid].y<buf) lo=mid+1;
                    else hi=mid-1;
              }
              for(int j=end;j<lo;j++)
                   update(Bin(hh[j].x),Bin((__int64)hh[j].x+W)-1,hh[j].val,1);
              end=lo;
              if(ans<tt[1].val) ans=tt[1].val;
              if(end==n) break;
         }
         printf("%d\n",ans);
    }
}


