#include<stdio.h>
const int N=101,M=100001;
int n,m;
int a[N],c[N],num[M];
bool flag[M];
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=0;i<=m;++i) flag[i]=false;
        flag[0]=true;
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int j=1;j<=n;++j) scanf("%d",&c[j]);
        for(int i=1;i<=n;++i)
        {
             for(int j=0;j<=m;++j) num[j]=0;
             for(int j=a[i];j<=m;++j)
                if(!flag[j]&&flag[j-a[i]]&&num[j-a[i]]<c[i])
                    flag[j]=true,num[j]=num[j-a[i]]+1;
        }
        int cnt=0;
        for(int i=1;i<=m;++i)
            if(flag[i]) ++cnt;
        printf("%d\n",cnt);
    }
}
