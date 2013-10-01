#include<stdio.h>
const int N=1000100,M=10010;
int pre[N],idx[M],cnt=0;
int Find(int x)
{
    int r=x;
    while(pre[r]>=0) r=pre[r];
    while(r!=x)
    {
        int t=pre[x];
        pre[x]=r;
        x=t;
    }
    return r;
}
void Union(int x,int y)
{
    int r1=Find(x),r2=Find(y),t1=pre[r1],t2=pre[r2];
    if(pre[r1]<pre[r2]) pre[r1]+=t2,pre[r2]=r1;
    else pre[r2]+=t1,pre[r1]=r2;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
    for(int i=1;i<=n;i++) idx[i]=i,pre[i]=-1;
    cnt=n+1;
    char s[2];
    int x,y,yes=0,no=0;
    while(scanf("%s",s),s[0]!='e')
    {
          switch (s[0])
          {
               case 'c':
                    scanf("%d%d",&x,&y);
                    if(Find(idx[x])!=Find(idx[y]))
                         Union(idx[x],idx[y]);
                    break;
               case 'q':
                    scanf("%d%d",&x,&y);
                    if(Find(idx[x])==Find(idx[y])) yes++;
                    else no++;
                    break;
               case 'd':
                    scanf("%d",&x);
                    idx[x]=cnt++;
                    pre[idx[x]]=-1;
                    break;
          }
    }
    printf("%d , %d\n",yes,no);
    }
}
