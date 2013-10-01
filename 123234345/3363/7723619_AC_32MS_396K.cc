#include<stdio.h>
const int N=101;
char f[N][N];
int main()
{
    int n,m,r,c;
    while(scanf("%d%d%d%d",&n,&m,&r,&c),n)
    {
        for(int i=1;i<=n;i++)
            scanf("%s",f[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                  f[i][j]-='0';
        int ans=0;
        for(int i=1;i+r-1<=n;i++)
           for(int j=1;j+c-1<=m;j++)
              if(f[i][j])
              {
                   ans++;
                   for(int x=1;x<=r;x++)
                      for(int y=1;y<=c;y++)
                         f[i+x-1][j+y-1]^=1;
              }
        int flag=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                 if(f[i][j]) flag=1;
        printf("%d\n",flag?-1:ans);
    }
}
