#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3fffffff;
int f[2][4000][2],a[4000];
int n,b;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d",&n,&b);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int k=0;k<=b;k++) f[0][k][0]=f[0][k][1]=-inf;
    f[0][0][0]=0,f[0][1][1]=0;
    int now=0;
    for(int i=1;i<n;i++)
    {
         now^=1;   
         f[now][0][1]=-inf;
         for(int j=1;j<=b;j++)
         {
             f[now][j][0]=max(f[now^1][j][1],f[now^1][j][0]);
             f[now][j][1]=max(f[now^1][j-1][0],f[now^1][j-1][1]+a[i]);
         }
    }
    
    int ans=max(f[now][b][0],f[now][b][1]);
    for(int k=0;k<=b;k++) f[0][k][0]=f[0][k][1]=-inf;
    f[0][0][0]=0,f[0][1][1]=a[0];
    now=0;
    for(int i=1;i<n;i++)
    {
         now^=1;   
         f[now][0][1]=-inf;
         for(int j=1;j<=b;j++)
         {
             f[now][j][0]=max(f[now^1][j][1],f[now^1][j][0]);
             f[now][j][1]=max(f[now^1][j-1][0],f[now^1][j-1][1]+a[i]);
         }
    }
    ans=max(ans,f[now][b][1]);
    printf("%d\n",ans);
}
