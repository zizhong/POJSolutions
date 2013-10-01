#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const __int64 inf=1LL<<60;
struct Node
{
    int k;
    __int64 x;
}rec1[1<<18],rec2[1<<18];
void calc_rec(Node *rec,int &cnt,__int64 *d,int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        __int64 tmp=0;
        for(int j=0;j<n;j++) if(i&(1<<j)) tmp+=d[j];
        rec[cnt].k=i;
        rec[cnt++].x=tmp;
    }
}
bool cmp(const Node &n1,const Node &n2)
{
    return n1.x<n2.x;
}
int cntbit(int x)
{
    int r=0;
    while(x) r+=x&1,x>>=1;
    return r;
}
__int64 _abs(__int64 x){return x>0?x:-x;}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        __int64 num[36];
        for(int i=0;i<n;i++)
            scanf("%I64d",&num[i]);
        if(n==1)
        {
            printf("%I64d 1\n",_abs(num[0]));
            continue;
        }
        int n1=n>>1,n2=n-n1;
        __int64 d1[36],d2[36];
        for(int i=0;i<n1;i++) d1[i]=num[i];
        for(int j=0;j<n2;j++) d2[j]=num[j+n1];
        int cnt1=0,cnt2=0;
        calc_rec(rec1,cnt1,d1,n1);
        calc_rec(rec2,cnt2,d2,n2);
        __int64 ans=inf,cnt=inf;
        for(int i=1;i<cnt1;i++)
        {
            if(ans>_abs(rec1[i].x))
                 ans=_abs(rec1[i].x),cnt=cntbit(rec1[i].k);
            else if(ans==_abs(rec1[i].x) && cnt>cntbit(rec1[i].k))
                cnt=cntbit(rec1[i].k);
        }
        for(int i=1;i<cnt2;i++)
        {
            if(ans>_abs(rec2[i].x))
                 ans=_abs(rec2[i].x),cnt=cntbit(rec2[i].k);
            else if(ans==_abs(rec2[i].x) && cnt>cntbit(rec2[i].k))
                cnt=cntbit(rec2[i].k);
        }
        //printf("test: %I64d %I64d\n",ans,cnt);
        sort(rec1,rec1+cnt1,cmp);
        for(int i=1;i<cnt2;i++)
        {
            __int64 key=-rec2[i].x;
            int l=0,r=cnt1-1;
            while(l+1<r)
            {
                int m=l+r>>1;
                if(rec1[m].x>key) r=m;
                else l=m;
            }
            int idx;
            if(_abs(rec1[l].x-key)<_abs(rec1[r].x-key)) idx=l;
            else idx=r;
            //printf("%I64d %d %d\n",rec1[idx].x,rec1[idx].k,i);
            if(_abs(rec1[idx].x-key)>ans) continue;
            int flag=(_abs(rec1[idx].x-key)==ans);
            ans=_abs(rec1[idx].x-key);
            __int64 min=inf;
            while(idx>0 && rec1[idx-1].x==rec1[idx].x) idx--;
            for(int j=idx;j<cnt1 && rec1[j].x==rec1[idx].x;j++)
            {
                __int64 tmp=cntbit(rec1[j].k)+cntbit(rec2[i].k);
                if(min>tmp)
                     min=tmp;
            }
            if(flag) 
            {
               if(cnt>min) 
                   cnt=min;
            }else cnt=min;
        }
        printf("%I64d %I64d\n",ans,cnt);
    }
}
