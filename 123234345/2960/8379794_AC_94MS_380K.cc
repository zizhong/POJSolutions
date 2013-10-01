#include<stdio.h>
const int N=110,M=10010;
int k,set[N],SG[M];
void cal_SG()
{
     for(int i=0;i<M;i++)
     {
          int v[N]={0};
          for(int j=0;j<k;j++)
             if(i-set[j]>=0&&SG[i-set[j]]<N) v[SG[i-set[j]]]=1;
          int t=0;
          while(v[t]) ++t;
          SG[i]=t;
     }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&k),k)
    {
         for(int i=0;i<k;i++) scanf("%d",&set[i]);
         cal_SG();
         int T;
         scanf("%d",&T);
         while(T--)
         {
              int n,sg=0,d;
              scanf("%d",&n);
              for(int i=0;i<n;i++)
                  scanf("%d",&d),sg^=SG[d];
              putchar(sg?'W':'L');
         }
         puts("");
    }
}
