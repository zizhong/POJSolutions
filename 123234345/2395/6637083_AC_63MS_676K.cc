#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int M=10001,N=2001;
struct LEN
{
       short a,b;
       int w;
}len[M];
int pre[N];
int n,m,ans;
int cmp(const void *a,const void *b)
{
    LEN* p1=(LEN*)a;
    LEN* p2=(LEN*)b;
    return p1->w - p2->w;
}
int find(int x)
{
    int r=x;
    while(pre[r]>=0)
         r=pre[r];
    while(r!=x)
    {
          int t=pre[x];
          pre[x]=r;
          x=t;
    }
    return r;
}
void Union(int a,int b)
{
    int t1=find(a),t2=find(b),tp=pre[t1]+pre[t2];
    if(pre[t1]<pre[t2])  pre[t2]=t1,pre[t1]=tp;
    else pre[t1]=t2,pre[t2]=tp;
}
int  MST()
{
     int add=0,cur=0;
     while(true)
     {
          if(find(len[cur].a)!=find(len[cur].b))
          {
                add++;
                Union(len[cur].a,len[cur].b);                                
          }
          if(add>=n-1) return len[cur].w;
          cur++;
     }
}
int main()
{
    memset(pre,-1,sizeof(pre));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
         scanf("%d%d%d",&len[i].a,&len[i].b,&len[i].w);
    }
    qsort(len,m,sizeof(len[0]),cmp);
    printf("%d\n",MST());
    system("pause");
}
