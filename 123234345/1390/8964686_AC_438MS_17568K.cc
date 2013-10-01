#include<stdio.h>
#include<cstring>
const int N=210;
int len[N],clr[N],pre[N],rst[N];
int f[N][N][N];
int n,m;
void init()
{
     scanf("%d%d",&n,&clr[1]);
     m=1,len[1]=1;
     for(int i=2;i<=n;i++)
     {
         int x;    
         scanf("%d",&x);
         if(x==clr[m]) ++len[m];
         else
         {
             m++;
             clr[m]=x,len[m]=1;
         }
     }
}
void prep()
{
     memset(pre,0,sizeof(pre));
     memset(rst,0,sizeof(rst));
     for(int i=m;i>=2;i--) for(int j=i-1;j>=1;j--)
     if(clr[i]==clr[j])
     {
         pre[i]=j;
         rst[j]=len[i]+rst[i];
         break;
     }
     for(int i=1;i<=m;i++)
         for(int j=0;j<=rst[i];j++) 
             f[i][i][j]=(len[i]+j)*(len[i]+j);
}
int dp()
{
    for(int l=2;l<=n;l++)
       for(int i=1;i<=m+1-l;i++)
       {
            int j=i+l-1;
            for(int k=0;k<=rst[j];k++)
            {
                 f[i][j][k]=f[i][j-1][0]+(len[j]+k)*(len[j]+k);
                 int p=pre[j];
                 while(p>=i)
                 {
                      int x=f[i][p][k+len[j]]+f[p+1][j-1][0];
                      if(f[i][j][k]<x) f[i][j][k]=x;
                      p=pre[p];
                 }
            }    
       }
    return f[1][m][0];
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int nc=1;nc<=T;nc++)
    {
         init();
         prep();
         printf("Case %d: %d\n",nc,dp());
    }
}
