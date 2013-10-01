#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=101;
int g[N][N],rank[N],d[N],vst[N];
int m,n;
int OK(int a){return a>=0&&a<=m;}
void Dis(int R)
{
     vst[0]=1;
     for(int i=1;i<=n;i++) 
             if(OK(R-rank[i])) vst[i]=0,d[i]=g[0][i];
             else vst[i]=1,d[i]=g[0][1];
     while(1)
     {
             int min=99999999,tail=-1;
             for(int i=1;i<=n;i++)
                 if(vst[i]==0&&min>d[i])
                 {
                       tail=i;
                       min=d[i];
                 }
             if(tail==-1) break;
             vst[tail]=1;
             for(int i=1;i<=n;i++)
                if(vst[i]==0&&d[i]>d[tail]+g[tail][i])
                       d[i]=d[tail]+g[tail][i];
     }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<N;i++)
         for(int j=0;j<N;j++)
             if(i!=j) g[i][j]=99999999;    
    for(int i=1;i<=n;i++)
    {
         int p,l,x;
         scanf("%d%d%d",&p,&l,&x);
         rank[i]=l;
         g[0][i]=p;
         for(int j=0;j<x;j++)
         {
             int t,v;
             scanf("%d%d",&t,&v);
             g[t][i]=v;
         }
    }
    int ans=g[0][1];
    for(int i=1;i<=n;i++)
    {
          Dis(rank[i]);
          if(ans>d[1]) ans=d[1];
    }
    printf("%d\n",ans);
    system("pause");
}
