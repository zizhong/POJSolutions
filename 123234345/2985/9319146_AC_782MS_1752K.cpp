#include<cstdio>
#include<cmath>
#include<cstring>
const int N=200010;
int pre[N],c[N];
int n,m,tot;
int findr(int x)
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
int lowbit(int x){return x&(-x);}
void Bit_ins(int x,int cc)
{
     while(x<=n)
     {
          c[x]+=cc;
          x+=lowbit(x);
     }
}
void combine(int x,int y)
{
     int r1=findr(x),r2=findr(y);
     if(r1==r2) return;
     tot--;
     int num1=-pre[r1],num2=-pre[r2];
     Bit_ins(num1,-1),Bit_ins(num2,-1),Bit_ins(num1+num2,1);     
     if(num1>num2) pre[r2]=r1,pre[r1]=-(num1+num2);
     else pre[r1]=r2,pre[r2]=-(num1+num2);
}
int query(int k)
{
    int ans=0,cnt=0;
    for(int i=(int)(log(1.0*n)/log(2.0));i>=0;i--)
    {
         ans+=(1<<i);
         if(ans>=n||cnt+c[ans]>=k)
             ans-=(1<<i);
         else cnt+=c[ans];
    }
    return ans+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(c,0,sizeof(c));
    Bit_ins(1,n);
    tot=n;
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<m;i++)
    {
         int op;
         scanf("%d",&op);
         if(op==0) 
         {
              int x,y;
              scanf("%d%d",&x,&y);
              combine(x,y);
         }else
         {
              int k;
              scanf("%d",&k);
              printf("%d\n",query(tot+1-k));
         }
    }
}
