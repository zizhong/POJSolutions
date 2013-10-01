#include<stdio.h>
const int N=1024;
int x,state[N],f[61][61][101],n,m,g[101],num[N];
int genState()
{
    for(int i=0;i<(1<<m);i++)
    {
            if((i&(i<<1))|(i&(i<<2))|(i&(i>>1))|(i&(i>>2))) continue;
            state[++x]=i;            
            int k=0,ii=i;
            while(ii) k+=(ii&1),ii>>=1;
            num[x]=k;
    }
}
int main()
{
   
    scanf("%d%d",&n,&m);
    genState();
    for(int i=1;i<=n;i++)
    {
         char s[11];
         scanf("%s",s);
         int t=0;
         for(int j=0;j<m;j++)
               t=(t<<1)|(s[j]=='H');
         g[i]=t;
    }
    for(int i=1;i<=x;i++)
           if(!(g[1]&state[i]))  f[i][1][1]=num[i];
    for(int k=2;k<=n;k++)
            for(int t=1;t<=x;t++)
                for(int j=1;j<=x;j++)
                {
                      if(state[t]&state[j]) continue;
                      for(int i=1;i<=x;i++)
                      {
                            if((g[k]|state[t]|state[j])&state[i]) continue;
                                 if(f[i][j][k]<f[j][t][k-1]+num[i]) f[i][j][k]=f[j][t][k-1]+num[i];
                      }
                }
    int ans=0;
    for(int k=1;k<=n;k++)
       for(int i=1;i<=x;i++)
           for(int j=1;j<=x;j++)
               if(f[i][j][k]>ans) ans = f[i][j][k];
    printf("%d\n",ans);
    
 }
