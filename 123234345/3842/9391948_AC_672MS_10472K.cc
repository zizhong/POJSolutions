#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=8,M=9999999+1,pnum=664579;
char str[N];
bool p[M];
void init_p()
{
    p[0]=p[1]=true;
    for(int i=2;i<M;i++) if(p[i]==false)
    {
        for(int j=i+i;j<M;j+=i) p[j]=true;
    }
}
int res[pnum+1],cnt,n;
void calc(int x)
{
    char tmp[N];
    int nn=0;
    for(int i=0;i<n;i++) if(x&(1<<i))
         tmp[nn++]=str[i];
    tmp[nn]=0;
    sort(tmp,tmp+nn);
    do{
        int r=0;
        for(int i=nn-1;i>=0;i--) r=r*10+tmp[i]-'0';
        //printf("%d\n",r);
        if(p[r]==false) res[cnt++]=r;
    }while(next_permutation(tmp,tmp+nn));
}
int solve()
{
    n=strlen(str);
    cnt=0;
    for(int k=1;k<(1<<n);k++)
        calc(k);
    sort(res,res+cnt);
    int ans=(cnt>0);
    for(int i=1;i<cnt;i++) if(res[i-1]!=res[i])
         ans++;
    return ans;
}
int main()
{
    init_p();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        printf("%d\n",solve());
    }
}
