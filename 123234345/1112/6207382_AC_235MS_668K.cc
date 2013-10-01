#include<stdio.h>
#include<string.h>
const int N=105,Inf=1000000;
int n,m,v[N],s[N][2],f[N][N],p[N][N];
bool g[N][N];
void Init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
     {
           int j;
           while(scanf("%d",&j),j) g[i][j]=true;
     }
     for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            g[i][j]=g[j][i]=!(g[i][j]&&g[j][i]);
}
bool Dye(int i,int flag)
{
     v[i]=(flag)?-m:m,s[m][flag]++;
     for(int j=1;j<=n;j++) if(g[i][j])
        if(v[i]==v[j]||!v[j]&&!Dye(j,flag^1)) return false;
     return true;
}
void Dp()
{
     for(int i=0;i<N;i++) for(int j=0;j<N;j++)
          f[i][j]=-Inf;
     for(int j=0;j<=n/2;j++) f[0][j]=0;
     for(int i=1;i<=m;i++)
         for(int j=1;j<=n/2;j++)
             if(s[i][1])
             {
                  if(j>=s[i][0]) f[i][j]=f[i-1][j-s[i][0]]+s[i][0];
                  if(j>=s[i][1]&&f[i-1][j-s[i][1]]+s[i][1]>f[i][j])
                       f[i][j]=f[i-1][j-s[i][1]]+s[i][1],p[i][j]=1;
             }
             else
             {
                 f[i][j]=f[i-1][j],p[i][j]=-1;
                 if(j>=s[i][0]&&f[i-1][j-s[i][0]]+s[i][0]>f[i][j])
                      f[i][j]=f[i-1][j-s[i][0]]+s[i][0],p[i][j]=0;
             }
}
bool ans[N];
int rec[N];
void Print()
{
     int limit=n/2,now=m;
     while(now>0)
     {
           rec[now]=p[now][limit];
           if(rec[now]>-1) limit-=s[now][rec[now]];
           now--;
     }
     for(int i=1;i<=n;i++)
         if(v[i]>0&&rec[v[i]]==0) ans[i]=true;
         else if(v[i]<0&&rec[-v[i]]==1) ans[i]=true;
     printf("%d",f[m][n/2]);
     for(int i=1;i<=n;i++) if(ans[i]) printf(" %d",i);puts("");
     printf("%d",n-f[m][n/2]);
     for(int i=1;i<=n;i++) if(!ans[i]) printf(" %d",i);puts("");
}
bool Calc()
{
     for(int i=1;i<=n;i++) if(!v[i])
     {
           m++;
           if(!Dye(i,0)) return false;
     }
     return true;
}
int main()
{
    Init();
    if(!Calc())
    {
          puts("No solution");
          return 0;
    }
    Dp();
    Print();
    return 0;
}
