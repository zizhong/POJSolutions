#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int mask=(1<<20)-1;
void disp(int x)
{
     for(int i=0;i<20;i++) putchar(((x>>i)&1)+'0');puts("");
}
int calc(int x,int p)
{
    x^=p,x^=(p<<1),x^=(p>>1);
    return x&mask;
}
int solve(int s)
{
    int ans=0;
    for(int i=1;i<20;i++) if((s>>(i-1))&1)
    {
        ans++;
        s=calc(s,1<<i);
    }
    if(s==0) return ans;
    return mask;
}
int main()
{
    int s=0;
    for(int i=0;i<20;i++)
    {
         int x;
         scanf("%d",&x);
         s=s*2+x;
    }
    int s2=calc(s,1);
    int ans=min(solve(s),1+solve(s2));
    printf("%d\n",ans);
    scanf("%'d");
}
