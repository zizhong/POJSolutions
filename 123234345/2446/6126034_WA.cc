#include<stdio.h>
#include<string.h>
const int N=33,VN=600;
char g1[N][N],g[VN][VN],bin[N][N];
int num_v[N][N],num_x[VN],num_y[VN];
int x,y,x_lan[VN],y_lan[VN],vst[VN];
int _abs(int a){return a>0?a:-a;}
int dfs(int n_v,int level)
{
    for(int j=0;j<y;j++)
    {
         if(vst[j]!=level&&g[n_v][j])
         {
             vst[j]=level;
             if(y_lan[j]==-1||dfs(y_lan[j],level))
             {
                  y_lan[j]=n_v;
                  x_lan[n_v]=j;
                  return 1;
             }
         }
    }
    return 0;
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        int xi,yi;
        scanf("%d%d",&xi,&yi);
        g1[xi][yi]=1;
    }
    if((n*m-k)&1){puts("NO");return 0;}
    int vi=1;
    for(int i=1;i<=n;i++)
    {
         bin[i][1]=i&1;
         num_v[i][1]=vi++;
         for(int j=2;j<=m;j++)
         {
             bin[i][j]=bin[i][j-1]^1;
             num_v[i][j]=vi++;
         }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
           if(g1[i][j]) continue;
           if(bin[i][j]) num_x[x++]=num_v[i][j];
           else num_y[y++]=num_v[i][j];
        }
    for(int i=0;i<x;i++)
         for(int j=0;j<y;j++)
              if(_abs(num_x[i]-num_y[j])==1||_abs(num_x[i]-num_y[j])==m) g[i][j]=1;
    int ans=0;
    memset(x_lan,-1,sizeof(x_lan));
    memset(y_lan,-1,sizeof(y_lan));
    for(int i=0;i<x;i++)
    {
         if(x_lan[i]==-1)
         {
             if(dfs(i,i+1)) ans++;
         }
    }
    puts(ans*2+k==m*n?"YES":"NO");}
