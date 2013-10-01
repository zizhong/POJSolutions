#include<iostream>
using namespace std;
int n,a[5000],f[5000],c[5000],size;
int tot[5000][30],ans[30];
int bsearch(int *ci,int ai){
    int l=1,r=size-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ai<ci[mid-1]&&ai>=c[mid]) return mid;
        else if(ai<ci[mid]) l=mid+1;
        else r=mid-1;
    }
}
void add(int *ai,int *bi){
    if(bi[0]>ai[0]) ai[0]=bi[0];
    for(int i=1;i<=ai[0];++i) ai[i]+=bi[i];
    for(int i=1;i<=ai[0];++i){
        ai[i+1]+=ai[i]/10000;
        ai[i]%=10000;
    }
    if(ai[ai[0]+1]) ai[0]++;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i) scanf("%d",&a[i]);
    c[0]=a[0]; f[0]=size=1;
    int now;
    for(int i=1;i<n;++i){
        if(a[i]>=c[0]) now=0;
        else if(a[i]<c[size-1]) now=size++;
        else now=bsearch(c,a[i]);
        c[now]=a[i]; f[i]=now+1;
    }
    printf("%d ",size);
    for(int i=0;i<n;++i){
        memset(tot[i],0,sizeof(tot[i]));
        if(f[i]==1)
            tot[i][0]=tot[i][1]=1;
        else{
            tot[i][0]=1;
            now=-1;
            for(int j=i-1;j>=0;--j)
                if(f[j]+1==f[i]&&a[j]>a[i]&&now!=a[j]){
                    add(tot[i],tot[j]);
                    now=a[j];
                }
        }
    }
    now=-1;
    memset(ans,0,sizeof(ans));
    ans[0]=1;
    for(int i=n-1;i>=0;--i)
        if(f[i]==size&&now!=a[i]){
            add(ans,tot[i]);
            now=a[i];
        }
    printf("%d",ans[ans[0]]);
    for(int i=ans[0]-1;i>=1;--i) printf("%04d",ans[i]);
    printf("\n");
}