#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
    int x,k;
}rec1[1<<18],rec2[1<<18];
int calc_rec(Node *rec, int &cnt,int *d,int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        int tmp=0;
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
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        int num[36];
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        if(n==1)
        {
            printf("%d 1\n",num[0]);
            continue;
        }
        int n1=n>>1,n2=n-n1;
        int d1[36],d2[36];
        for(int i=0;i<n1;i++) d1[i]=num[i];
        for(int j=0;j<n2;j++) d2[j]=num[j+n1];
        int cnt1=0,cnt2=0;
        calc_rec(rec1,cnt1,d1,n1);
        calc_rec(rec2,cnt2,d2,n2);
        int ans=0x3fffffff,cnt=0x3fffffff;
        for(int i=1;i<cnt1;i++)
        {
            if(ans>abs(rec1[i].x))
                 ans=abs(rec1[i].x),cnt=cntbit(rec1[i].k);
            else if(ans==abs(rec1[i].x) && cnt>cntbit(rec1[i].k))
                cnt=cntbit(rec1[i].k);
        }
        for(int i=1;i<cnt2;i++)
        {
            if(ans>abs(rec2[i].x))
                 ans=abs(rec2[i].x),cnt=cntbit(rec2[i].k);
            else if(ans==abs(rec2[i].x) && cnt>cntbit(rec2[i].k))
                cnt=cntbit(rec2[i].k);
        }
        sort(rec1,rec1+cnt1,cmp);
        printf(".. %d\n",cnt2);
        for(int i=1;i<cnt2;i++)
        {
            if(rec2[i].x>ans || rec2[i].x==ans && cntbit(rec2[i].k)>=cnt)
                    continue;
            int key=-rec2[i].x;
            int l=0,r=cnt1-1;
            while(l+1<r)
            {
                int m=l+r>>1;
                if(rec1[m].x>key) r=m;
                else l=m;
            }
            int idx;
            if(abs(rec1[l].x-key)<abs(rec1[r].x-key)) idx=l;
            else idx=r;
            if(abs(rec1[idx].x-key)>ans) continue;
            ans=abs(rec1[idx].x-key);
            cnt=cntbit(rec2[i].k);
            int min=0x3fffffff;
            while(idx>0 && rec1[idx-1].x==rec1[idx].x) idx--;
            idx++;
            for(int j=idx;j<cnt1 && rec1[j].x==rec1[idx].x;j++)
            {
                int tmp=cntbit(rec1[j].k);
                if(min>tmp)
                     min=tmp;
            }
            cnt+=min;
        }
        printf("%d %d\n",ans,cnt);
    }
}
