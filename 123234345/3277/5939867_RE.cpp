#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;
const int MAXN=40000;
struct Line
{
       int i,h,left,right,mid;
};
struct Build
{
       int a,b,h;
}b[MAXN];
Line segt[MAXN*6];
int suf[MAXN*2];
int s[MAXN*2];
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
     if(l+1==r)return ;
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
     if(segt[num].mid>=r) insert(l,r,h,2*num);
     else if(segt[num].mid<=l) insert(l,r,h,2*num+1);
     else insert(l,mid,h,2*num),
          insert(mid,r,h,2*num+1);
}
__int64 cal(int l,int r,int h,int num)
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
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
         scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].h);
         suf[i*2]=b[i].a,suf[i*2+1]=b[i].b;
    }
    qsort(suf,n*2,sizeof(suf[0]),cmp);
    map<int ,int>mp;
    int j=0,t=-1;
    for(int i=0;i<n*2;i++)
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
    int m=j;
    create(0,m-1,1);
    for(int i=0;i<n;i++)
       insert(mp[b[i].a],mp[b[i].b],b[i].h,1);
    printf("%I64d\n",cal(0,m-1,0,1));
    //system("pause");
}
