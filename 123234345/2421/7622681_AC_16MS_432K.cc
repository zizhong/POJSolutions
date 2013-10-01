#include<stdio.h>
const int N=101;
int g[N][N];
int MST(int n)
{
    int d[N],v[N];
    for(int i=1;i<=n;i++)
    {
         d[i]=g[1][i];
         v[i]=0;
    }
    v[1]=1;
    while(1)
    {
         int min=0x7fffffff,tail=-1;
         for(int i=1;i<=n;i++)
             if(min>d[i]&&v[i]==0)
                 min=d[i],tail=i;
         if(tail==-1) break;
         v[tail]=1;
         for(int i=1;i<=n;i++)
             if(v[i]==0&&d[i]>g[tail][i])
                  d[i]=g[tail][i]; 
    }
    int sum=0;
    for(int i=1;i<=n;i++) sum+=d[i];
    return sum;
}
int main ()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
           scanf("%d",&g[i][j]);
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
         int a,b;
         scanf("%d%d",&a,&b);
         g[a][b]=g[b][a]=0;
    }
    printf("%d\n",MST(n));
    scanf("%'d");
}
