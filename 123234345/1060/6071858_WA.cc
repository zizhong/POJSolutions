#include<stdio.h>
const int N=1001;
char ans[N*N];
int main()
{
    int nt;
    scanf("%d",&nt);
    while(nt--)
    {
          int nf,f[N]={0},ng,g[N]={0},nh,h[N]={0};
          scanf("%d",&nf);
          nf--;
          for(int i=nf;i>=0;i--) scanf("%d",&f[i]);
          scanf("%d",&ng);
          ng--;
          for(int i=ng;i>=0;i--) scanf("%d",&g[i]);
          scanf("%d",&nh);
          nh--;
          for(int i=nh;i>=0;i--) scanf("%d",&h[i]);
          int na=ng*nf;
          for(int i=0;i<=na;i++) ans[i]=0;
          for(int i=0;i<=nf;i++)
          {
              if(f[i])
              for(int j=0;j<=ng;j++)
                  if(g[j])
                     ans[i+j]^=1;
          }
          for(int i=na;i>=nh;i--)
              if(ans[i])
              {
              int d=i-nh;
              for(int j=nh;j>=0;j--)
                  if(h[j])
                     ans[j+d]^=1;
              }
          int k=nh;
          while(!ans[k--]) ;
          printf("%d 1",k+2);
          for(;k>=0;k--) printf(" %d",ans[k]);
          puts("");           
    }
}
