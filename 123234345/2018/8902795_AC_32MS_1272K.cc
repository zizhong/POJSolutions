#include<stdio.h>
#define lld long long
const int N=100010;
int q[N],head,tail;
long long d[N];
int n,k;
double f(int x,long long y){return (d[y]*1.0-d[x])/(y-x);}
lld readT()
{
    char c;
    lld ret;
    while(c=getchar(),c<'0'||c>'9');
    ret = c - '0';
    while(c=getchar(),c>='0'&&c<='9')ret = ret * 10 + c-'0';
    return ret;
}
int main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
          for(int i=1;i<=n;i++) d[i]=readT(),d[i]+=d[i-1];
          double ans=0;
          head=tail=0;
          for(int i=k;i<=n;i++)
          {
                //while(head<tail-1 && f(q[tail-2],q[tail-1])>=f(q[tail-1],i-k)) tail--;
                while(head<tail-1 && (d[q[tail-1]]-d[q[tail-2]])*((i-k)-q[tail-1])>=(d[i-k]-d[q[tail-1]])*(q[tail-1]-q[tail-2])) tail--;
                q[tail++]=i-k;
                //while(head<tail-1 && f(q[head],i)<=f(q[head+1],i)) head++;
                while(head<tail-1 && (d[i]-d[q[head]])*(i-q[head+1])<= (d[i]-d[q[head+1]])*(i-q[head])) head++;
                double tmp=f(q[head],i); 
                if(tmp>ans) ans=tmp;
          }
          printf("%d\n",(int)(ans*1000));
    }
}

