#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
const int MAXN=41000;
struct Line
{
       int i,h,left,right,mid;
};
struct Build
{
       int a,b,h;
}b[MAXN];
Line segt[MAXN*6];
int suf[MAXN*2+2];
int s[MAXN*2+2];
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void create(int l,int r,int num)
{
     int mid=(l+r)>>1;
     segt[num].left=l;
     segt[num].right=r;
     segt[num].h=0;
     segt[num].mid=mid;
     if(l+1==r) return ;
     create(l,mid,2*num);
     create(mid,r,2*num+1);
}
void insert(int l,int r,int h,int num)
{
     if(segt[num].left==l&&segt[num].right==r)
     {
          if(segt[num].h)
               h=h<segt[num].h?segt[num].h:h;
          segt[num].h=h;
          return ; 
     }
     int mid=segt[num].mid;
     if(mid>=r) insert(l,r,h,2*num);
     else if(mid<=l) insert(l,r,h,2*num+1);
     else insert(l,mid,h,2*num),
          insert(mid,r,h,2*num+1);
}
__int64 cal(int h,int num)
{
        int r=segt[num].right,l=segt[num].left;
        if(segt[num].h<h) segt[num].h=h;
        if(l+1==r)
              return ((__int64 )segt[num].h)*(s[r]-s[l]);
        return cal(segt[num].h,2*num)+cal(segt[num].h,2*num+1);
}
int main()
{
    int  n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].h);
         suf[i*2]=b[i].a,suf[i*2+1]=b[i].b;
    }
    qsort(suf,n*2,sizeof(suf[0]),cmp);
    map<int,int>mp;
    int j=0,t=-1;
    for(int i=0;i<n*2;i++)
    {
         if(t==suf[i])
         {
            suf[i]=-1;
            continue;
         }
         t=suf[i];
         ++j;
         s[j]=t;
         mp[t]=j;
    }
    int  m=j;    
    create(1,m,1);
    for(int  i=0;i<n;i++)
       insert(mp[b[i].a],mp[b[i].b],b[i].h,1);
    printf("%I64d\n",cal(segt[1].h,1));
}
