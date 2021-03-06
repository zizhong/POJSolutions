#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
const long long W=1LL<<31;
set<long long>myset;
long long q[1000*1000];
int step[1000*1000];
int head,tail;
int p;
void insert(long long w1,long long w2)
{
     if(w1>w2) swap(w1,w2);
     long long key=w1*W+w2;
     if(myset.find(key)!=myset.end()) return;
     myset.insert(key);
     step[tail]=step[head-1]+1;
     q[tail++]=key;
}
int main()
{
    scanf("%d",&p);
    myset.clear();
    myset.insert(0);
    myset.insert(0*W+1);
    q[tail++]=1LL;
    step[0]=0;
    while(head!=tail)
    {
          //printf("%d\n",head);
         long long cur=q[head++];
         long long w1=cur/W,w2=cur%W;
         if(w1==p||w2==p) {printf("%d\n",step[head-1]);break;}
         insert(0,w1);
         insert(0,w2);
         insert(2*w1,w1);
         insert(2*w1,w2);
         insert(2*w2,w2);
         insert(2*w2,w1);
         insert(w1+w2,w1);
         insert(w1+w2,w2);
         insert(w2-w1,w1);
         insert(w2-w1,w2);
    }
    scanf("%'d");
}
