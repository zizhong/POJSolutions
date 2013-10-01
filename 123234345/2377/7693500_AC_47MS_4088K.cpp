#include<stdio.h>
const int LV=100001,N=1001;
int g[N][N];
int min(int a,int b){return a<b?a:b;}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           if(i-j) g[i][j]=LV;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        g[a][b]=min(g[a][b],LV-w);
        g[b][a]=g[a][b];
    }
    int d[N],v[N]={0};
    for(int i=1;i<=n;i++)
         d[i]=g[1][i];
    v[1]=1;
    while(1)
    {
         int min=LV,mi=-1;
         for(int i=1;i<=n;i++)
              if(!v[i]&&d[i]<min)
                   min=d[i],mi=i;
         if(mi==-1) break;
         v[mi]=1;
         for(int i=1;i<=n;i++)
              if(!v[i]&&d[i]>g[mi][i])
                  d[i]=g[mi][i];
    }
    for(int i=2;i<=n;i++)
    {
        if(v[i]==0)
        {
             puts("-1");
             return 0;
        }
    }
    int ans=0;
    for(int i=2;i<=n;i++)
          ans+=(LV-d[i]);
    printf("%d\n",ans);
    
}
