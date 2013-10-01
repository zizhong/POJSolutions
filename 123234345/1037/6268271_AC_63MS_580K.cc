#include<stdio.h>
#include<string.h>
const int N=21;
__int64 W[N][N],M[N][N],used[N],c;
int n;
__int64 gU(int x,int n);
__int64 gD(int x,int n)
{
        if(W[x][n]!=-1) return W[x][n];
        __int64 ans=0;
        for(int i=1;i<x;i++) ans+=gU(i,n-1);
        return W[x][n]=ans;
}
__int64 gU(int x,int n)
{
        if(M[x][n]!=-1) return M[x][n];
        return M[x][n]=gD(n-x+1,n);
}
void Init()
{
     memset(W,-1,sizeof(W));
     memset(M,-1,sizeof(M));
     for(int i=1;i<N;i++) W[1][i]=0;
     W[1][1]=M[1][1]=1;
     W[1][2]=0,M[1][2]=1;
     W[2][2]=1,M[2][2]=0;
     for(int i=3;i<N;i++)
         for(int j=1;j<=i;j++)
             gD(j,i),gU(j,i);
}
void Output(int x,int k)
{
     do{
                for(int i=1;i<=k;i++)
                    if(used[i]&&x>=i) x++,k++;
     }while(used[x]);
     if(k>1) printf("%d ",x);
     else printf("%d",x);
     used[x]=1;
}
void solve()
{
     int up=1,first=1,i=1;
     memset(used,0,sizeof(used));
     while(n>0)
     {
               if(up==1)
               {
                        if(c>M[i][n])
                        {
                                     if(first) up=!up;
                                     c-=M[i][n];i++;
                        }else
                        {
                             Output(i,n);
                             first=0;
                             up=!up,n--;
                        }
               }else
               {
                    if(c>W[i][n])
                    {
                                 if(first) up=!up;
                                 c-=W[i][n];
                                 if(!first) i++;
                    }else
                    {
                         Output(i,n);
                         first=0;
                         up=!up;
                         n--;
                         i=1;
                    }
               }
     }
     puts("");
}
int main()
{
    int T;
    scanf("%d",&T);
    Init();
    while(T--)
    {
         scanf("%d%I64d",&n,&c);
         solve();
    }
}

