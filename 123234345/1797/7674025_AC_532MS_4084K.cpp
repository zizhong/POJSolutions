#include<stdio.h>
#include<string.h>
const int N=1001;
int g[N][N];
int min(int a,int b){return a>b?b:a;}
int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=0;i<m;i++)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            g[a][b]=g[b][a]=w;
        }
        int d[N],v[N];
        for(int i=1;i<=n;i++)
           d[i]=g[i][1],v[i]=0;
        while(1)
        {
            int max=0,mi=-1;
            for(int i=2;i<=n;i++)
                if(!v[i]&&d[i]>max) max=d[i],mi=i;
            if(mi==-1) break;
            v[mi]=1;
            for(int i=2;i<=n;i++)
                if(!v[i]&&d[i]<min(g[i][mi],d[mi]))
                    d[i]=min(g[i][mi],d[mi]);
        }
        printf("Scenario #%d:\n%d\n\n",tt,d[n]);
    }
}
