#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=50010;
int n,m;
int lsum[N<<2],rsum[N<<2],msum[N<<2],cover[N<<2];
void pushDown(int r,int m)
{
     if(cover[r]!=-1)
     {
         cover[r*2]=cover[2*r+1]=cover[r];
         lsum[2*r]=rsum[2*r]=msum[2*r]=cover[r]?0:(m+1)/2;
         lsum[2*r+1]=rsum[2*r+1]=msum[2*r+1]=cover[r]?0:m/2;
         cover[r]=-1;
     }
}
void pushUp(int r,int m)
{
     lsum[r]=lsum[2*r];
     rsum[r]=rsum[2*r+1];
     if(lsum[r]==(m+1)/2) lsum[r]+=lsum[2*r+1];
     if(rsum[r]==m/2) rsum[r]+=rsum[2*r];
     msum[r]=max(max(msum[2*r],msum[2*r+1]),rsum[2*r]+lsum[2*r+1]);
}
void build(int l,int r,int i)
{
     lsum[i]=rsum[i]=msum[i]=r-l+1;
     cover[i]=-1;
     if(l==r) return ;
     int m =l+r>>1;
     build(l,m,2*i);
     build(m+1,r,2*i+1);
}
void update(int x,int y,int c,int l,int r,int i)
{
     if(x<=l && r<=y)
     {
          lsum[i]=rsum[i]=msum[i]=c?0:r-l+1;
          cover[i]=c;
          return ;
     }
     if(l==r) return ;
     pushDown(i,r-l+1);
     int m=l+r>>1;
     if(x<=m) update(x,y,c,l,m,i*2);
     if(m<y) update(x,y,c,m+1,r,i*2+1);
     pushUp(i,r-l+1);
}
int query(int x,int l,int r,int i)
{
    if(l==r) return l;
    pushDown(i,r-l+1);
    int m=l+r>>1;
    if(msum[2*i]>=x) return query(x,l,m,2*i);
    if(rsum[2*i]+lsum[2*i+1]>=x) return m-rsum[2*i]+1; 
    return query(x,m+1,r,2*i+1);
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
          build(1,n,1);
          while(m--)
          {
               int type,x,y;
               scanf("%d",&type);
               if(type==1)
               {
                    scanf("%d",&x);
                    if(msum[1]<x) {puts("0");continue;}
                    int l=query(x,1,n,1);
                    printf("%d\n",l);
                    update(l,l+x-1,1,1,n,1);
               }else
               {
                    scanf("%d%d",&x,&y);
                    update(x,y+x-1,0,1,n,1);
               }
          }
    }
}
