#include<cstdio>
#include<cstring>
#include<cmath>
const int N=50006;
int c[N];
int lowbit(int k){return k&(-k);}
void modify(int k,int val)
{
     for(int i=k;i<N;i+=lowbit(i))
         c[i]+=val;
}
int getsum(int k)
{
    int ans=0;
    for(int i=k;i>0;i-=lowbit(i))
         ans+=c[i];
    return ans;
}
int findK(int K) //find Kth minimum
{
    int ans=0,cnt=0;
    for(int i=log(1.0*N-1)/log(2.0);i>=0;i--)
    {
         ans+=(1<<i);
         if(ans>=N||cnt+c[ans]>=K)
              ans-=(1<<i);
         else cnt+=c[ans];         
    }
    return ans+1;
}
int st[N],top;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        top=0;
        memset(c,0,sizeof(c));
        modify(1,1);
        modify(n+2,1);
        while(m--)
        {
             char cmd[2];
             int x;
             scanf("%s",cmd);
             if(cmd[0]!='R') scanf("%d",&x),x++;
             switch(cmd[0])
             {
                 case 'D':
                      modify(x,1);
                      st[top++]=x;
                      break;
                 case 'R':
                      modify(st[--top],-1);
                      break;
                 case 'Q':
                      int k=getsum(x);
                      if(k-getsum(x-1)==1) puts("0");
                      else printf("%d\n",findK(k+1)-findK(k)-1);
             } 
        }
    }
}
