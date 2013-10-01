#include<stdio.h>
int cal_len(long long x)
{
     int ans=0;
     while(x) ans++,x/=10;
     return ans;
}
void putdot(int x){if(x<0) return ; while(x--) putchar('.');}
void put_one(int x)
{
     putdot(x-1>>1);
     putchar('1');
     putdot(x>>1);
}
void putdash(int x){if(x<0) return ; while(x--) putchar('-');}
void put_num(long long x)
{
     int top=0,st[64];
     while(x) st[top++]=x%10,x/=10;
     while(top) putchar(st[--top]+'0');
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long p,q,T=0;
    while(scanf("%lld%lld",&p,&q),p)
    {
        long long d[100]={0},n=0;
        printf("Case %lld:\n%lld / %lld\n",++T,p,q);
        for(n=0;q;n++)
        {
             d[n]=p/q;
             long long t=p;
             p=q;
             q=t%q;
        }
        d[n-1]--,d[n++]=1;
        //for(int i=0;i<n;i++) put_num(d[i]),putchar(' ');
        int len[100],L=0;
        for(int i=0;i<n;i++)
            len[i]=cal_len(d[i]),L+=len[i];
        
        L+=3*(n-1);
        int idx=len[0]+3;
        for(int i=0;i<n-1;i++)
        {
             putdot(idx),put_one(L-idx),puts("");
             putdot(idx-len[i]-3),put_num(d[i]),putchar('.'),putchar('+'),putchar('.');
             putdash(L-idx),puts("");
             idx+=len[i+1]+3;
        }
        putdot(L-1),puts("1"); 
    }
}
