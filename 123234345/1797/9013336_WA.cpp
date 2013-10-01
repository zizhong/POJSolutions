
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
bool hash[97][20101];
int q[1000*1000][3];
int head,tail;
int flag;
int p,x;
long gcd(long a,long  b)
{
     return b?gcd(b,a%b):a;
}
void insert(int w1,int w2)
{
     if(flag) return ;
     if(w1==p ||w2 == p) {printf("%d\n",x+1);flag=1;return ;}
     if(w1>w2) swap(w1,w2);
     if(w1>=97||w2>p+97||w1==w2) return;
     if(hash[w1][w2]) return;
     hash[w1][w2]=1;
     q[tail][0]=w1,q[tail][1]=w2,q[tail][2]=x+1;
     tail++;
}
int main()
{
    scanf("%d",&p);
    x=-1;
    insert(0,1);
    while(!flag && head!=tail)
    {
          //printf("%d\n",head);
          int w1=q[head][0],w2=q[head][1];
          x=q[head++][2];
         insert(2*w1,w1);
         insert(2*w1,w2);
         insert(2*w2,w2);
         insert(2*w2,w1);
         insert(w1+w2,w1);
         insert(w1+w2,w2);
         //insert(w2-w1,w1);
         insert(w2-w1,w2);
    }
    scanf("%'d");
}
