#include<stdio.h>
const int N=1000001;
int wa[N],wb[N],wv[N],ws[N];
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) ws[i]=0;
     for(i=0;i<n;i++) ws[x[i]=r[i]]++;
     for(i=1;i<m;i++) ws[i]+=ws[i-1];
     for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
     for(j=p=1;p<n;j*=2,m=p)
     {
          for(p=0,i=n-j;i<n;i++) y[p++]=i;
          for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
          for(i=0;i<n;i++) wv[i]=x[y[i]];
          for(i=0;i<m;i++) ws[i]=0;
          for(i=0;i<n;i++) ws[wv[i]]++;
          for(i=1;i<m;i++) ws[i]+=ws[i-1];
          for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
          for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
          x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
}
int rank[N],height[N];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++) ;
}
int r[N],sa[N];
int ok(int x,int n,int k)
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
         if(height[i]<x) num=0;
         else
         {
             num++;
             if(num>=k-1) return 1;
         }
    }
    return 0;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",&r[i]),r[i]++;;
    r[n]=0;
    da(r,sa,n+1,N+1);
    calheight(r,sa,n);
    int l=1,r=n,mid;
    while(l+1<r)
    {
         mid=l+r>>1;
         if(ok(mid,n,k)) l=mid;
         else r=mid;
    }
    printf("%d\n",l);
}
