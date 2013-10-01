#include<stdio.h>
#include<string.h>
const int inf=1<<30,N=16;
int n,f[(1<<15)+1][N];
int x1[N],y1[N],x2[N],y2[N],cl[N],need[N];
void init()
{
     memset(need,0,sizeof(need));
     for(int i=0;i<n;i++)
     {
          for(int j=0;j<n;j++)
          {
                  if(i==j) continue;
                  if(x1[i]>=x2[j]&&y2[j]>y1[i]&&y1[j]<y2[i]) need[i]|=(1<<j);
          }
     }
}
void dp()
{
     for(int s=0;s<(1<<n);s++)
         for(int i=0;i<n;i++)
              f[s][i]=inf;
     for(int i=0;i<n;i++)
         if(need[i]==0) f[(1<<i)][i]=1;
     for(int s=0;s<(1<<n);s++)
           for(int i=0;i<n;i++)
           {
                 if(s&(1<<i)) continue;
                 for(int j=0;j<n;j++)
                 {
                       if(s&(1<<j)==0) continue;
                       if(i==j||(need[i]&s)!=need[i]) continue;
                       if(f[s|(1<<i)][i]>f[s][j]+(cl[i]!=cl[j]))
                             f[s|(1<<i)][i]=f[s][j]+(cl[i]!=cl[j]);
                 }
           }
    int ans=inf;
    for(int i=0;i<n;i++)
         if(f[(1<<n)-1][i]<ans) ans=f[(1<<n)-1][i];
         
    printf("%d\n",ans); 
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         scanf("%d",&n);
         for(int i=0;i<n;i++)
               scanf("%d%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i],&cl[i]);
         init();
         dp();
    }
}
