#include<cstdio>
#include<cstring>
const int N=301,inf=N*N;
int g[N][N];
int co[N];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                 if(i!=j)  g[i][j]=inf;
                 else g[i][j]=0;
    for(int i=0;i<m;i++)
    {
        int t;
        scanf("%d",&t);
        for(int j=0;j<t;j++)
             scanf("%d",&co[j]);
        for(int j=0;j<t;j++)
            for(int h=j+1;h<t;h++)
                g[co[j]][co[h]]=g[co[h]][co[j]]=1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(g[i][k]<inf)
             for(int j=1;j<=n;j++) if(g[k][j]<inf && g[i][j]>g[k][j]+g[i][k])
                   g[i][j]=g[i][k]+g[k][j];
    int d[N]={0};
    for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
               d[i]+=g[i][j];
    //for(int i=1;i<=n;i++) printf("%d ",d[i]);puts("");
    double ans=inf*100.0;
    for(int i=1;i<=n;i++)
          if(ans>d[i]*100.0/(n-1))
               ans=d[i]*100.0/(n-1);
    printf("%.f\n",ans);
    //system("pause");
}
