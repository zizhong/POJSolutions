#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=100001;
struct Seg{int l,r;}tt[N*4];
int sa[N],toL[20][N],val[20][N];
int n,m;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void build(int l,int r,int d,int idx)
{
     tt[idx].l=l,tt[idx].r=r;
     if(r==l) return ;
     int mid=l+r>>1;
     int lsame=mid-l+1;
     for(int i=l;i<=r;i++)
         if(val[d][i]<sa[mid]) lsame--;
     int lpos=l,rpos=mid+1,same=0;
     for(int i=l;i<=r;i++)
     {
          if(i==l) toL[d][i]=0;
          else toL[d][i]=toL[d][i-1];
          if(val[d][i]<sa[mid]) 
              val[d+1][lpos++]=val[d][i],
              toL[d][i]++;
          else if(val[d][i]>sa[mid])
               val[d+1][rpos++]=val[d][i];
          else
          {
              if(same<lsame)
              {
                    same++;
                    val[d+1][lpos++]=val[d][i],
                    toL[d][i]++;
              }
              else val[d+1][rpos++]=val[d][i];
          }
     }
     build(l,mid,d+1,idx<<1);
     build(mid+1,r,d+1,idx<<1|1);
}
int query(int l,int r,int k,int d,int idx)
{
    if(l==r) return val[d][l];
    int s,ss;
    if(l==tt[idx].l) s=toL[d][r],ss=0;
    else s=toL[d][r]-toL[d][l-1],ss=toL[d][l-1];
    int nl,nr;
    if(s>=k)
    {
        return query(tt[idx].l+ss,tt[idx].l+ss+s-1,
               k,d+1,idx<<1);
    }
    else
    {
        int bb=l-tt[idx].l-ss;
        int b=r-l+1-s;
        int mid=tt[idx].l+tt[idx].r>>1;
        return query(mid+bb+1,mid+bb+b,k-s,d+1,idx<<1|1);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
         scanf("%d",&sa[i]);
         val[0][i]=sa[i];
    }
    qsort(sa+1,n,sizeof(sa[0]),cmp);
    build(1,n,0,1);
    while(m--)
    {
         int x,y,k;
         scanf("%d%d%d",&x,&y,&k);
         printf("%d\n",query(x,y,k,0,1));
    }
   scanf("%'d");
}
