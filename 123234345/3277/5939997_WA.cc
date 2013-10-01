#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<map>
using namespace std;
const __int64 MAXN=40000;
struct Line
{
       __int64 i,h,left,right,mid;
};
struct Build
{
       __int64 a,b,h;
}b[MAXN];
Line segt[MAXN*6];
__int64 suf[MAXN*2];
__int64 s[MAXN*2];
int cmp(const void *a,const void *b)
{
    return *(__int64 *)a-*(__int64 *)b;
}
void create(__int64 l,__int64 r,__int64 num)
{
     __int64 mid=(l+r)>>1;
     segt[num].left=l;
     segt[num].right=r;
     segt[num].h=0;
     segt[num].mid=mid;
     if(l+1==r)return ;
     create(l,mid,2*num);
     create(mid,r,2*num+1);
}
void insert(__int64 l,__int64 r,__int64 h,__int64 num)
{
     if(segt[num].left==l&&segt[num].right==r)
     {
          if(segt[num].h)
               h=h<segt[num].h?segt[num].h:h;
          segt[num].h=h;
          return ; 
     }
     __int64 mid=segt[num].mid;
     if(segt[num].mid>=r) insert(l,r,h,2*num);
     else if(segt[num].mid<=l) insert(l,r,h,2*num+1);
     else insert(l,mid,h,2*num),
          insert(mid,r,h,2*num+1);
}
__int64 cal(__int64 l,__int64 r,__int64 h,__int64 num)
{
        if(segt[num].h>h) h=segt[num].h;
        if(l+1==r)
              return (__int64)h*(s[r]-s[l]);
        if(segt[num].mid>=r) return cal(l,r,h,2*num);
        if(segt[num].mid<=l) return cal(l,r,h,2*num+1);
        return cal(l,segt[num].mid,h,2*num)+cal(segt[num].mid,r,h,2*num+1);
}
int main()
{
    __int64 n;
    //freopen("in.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%I64d",&n);
    printf("%I64d\n",n);
    for(__int64 i=0;i<n;i++)
    {
         scanf("%I64d%I64d%i64d",&b[i].a,&b[i].b,&b[i].h);
         suf[i*2]=b[i].a,suf[i*2+1]=b[i].b;
         //printf("%I64d %I64d %I64d\n",b[i].a,b[i].b,b[i].h);
    }
    qsort(suf,n*2,sizeof(suf[0]),cmp);
    map<__int64 ,int>mp;
    __int64 j=0,t=-1;
    for(__int64 i=0;i<n*2;i++)
    {
         if(t==suf[i])
         {
            suf[i]=-1;
            continue;
         }
         t=suf[i];
         s[j]=t;
         mp[t]=j++;
    }
    __int64 m=j;
    create(0,m,1);
    for(__int64 i=0;i<n;i++)
       insert(mp[b[i].a],mp[b[i].b],b[i].h,1);
    cout<<cal(0,m,0,0)<<endl;/**/
}
