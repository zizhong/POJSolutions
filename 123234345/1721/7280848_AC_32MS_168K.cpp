#include<stdio.h>
const int N=1001;
int f[N][2];
int main()
{
    int n,s,k=0,v[N],i,j,t;
    scanf("%d%d",&n,&s);
    for(i=1;i<=n;i++)
         scanf("%d",&f[i][k]),v[i]=-1;
    k^=1;
    j=1;
    for(i=1;i<=n;i++)  if(v[i]==-1)
    {
        int x=i;
        while(v[x]==-1) f[j++][k]=x,v[x]=0,x=f[x][k^1];
    }
    k^=1;
    while(s--)
    {
          for(i=1;i<=n;i++) if(i&1) f[i][k]=f[(i+1)/2][k^1];
          else f[i][k]=f[(n+1)/2+i/2][k^1];
          k^=1;
    }
    f[1][k]=f[2][k^1];
    for(int i=3;i<=n;i++) f[f[i-1][k^1]][k]=f[i][k^1];
    f[f[n][k^1]][k]=1;
    for(int i=1;i<=n;i++) printf("%d\n",f[i][k]);
}
