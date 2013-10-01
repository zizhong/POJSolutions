#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100010;
bool isnp[N];
int sum[N];
void pl_init()
{
    isnp[1]=true;
    for(int i=2;i<N;i++) if(!isnp[i])
    {
        for(int j=i+i;j<N;j+=i) isnp[j]=true;
    }
    for(int i=1;i<N;i++)
        sum[i]=(isnp[i]==false)+sum[i-1];
}
int main()
{
    pl_init();
    int a,b;
    while(scanf("%d%d",&a,&b),a!=-1)
    {
        if(a>b) swap(a,b);
        if(!a) a=1;
        printf("%d\n",sum[b]-sum[a-1]);
    }
}
