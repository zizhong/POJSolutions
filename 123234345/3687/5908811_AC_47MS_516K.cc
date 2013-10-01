#include<stdio.h>
#include<string.h>
#define clr(a) memset(a,0,sizeof(a))
const int N=200,M=40000;
int g[N][N],c[N],ans[N];
int main()
{
    int t,n,m,a,b,i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        clr(g),clr(c);
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(!g[--b][--a]) g[b][a]=1,++c[a];            
        }
        for(i=n-1;i>=0;--i)
        {
            for(j=n-1;j>=0&&c[j];--j) ;
            if(j<0) break;
            ans[j]=i+1,c[j]=-1;
            for(k=0;k<n;k++) if(g[j][k]) --c[k];
        }
        if(i>=0) printf("-1\n");
        else
        {
            printf("%d",ans[0]);
            for(i=1;i<n;i++) printf(" %d",ans[i]);
            puts("");
        }
    }
}