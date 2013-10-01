#include<stdio.h>
const int INF=0x7fffffff;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         int p[101]={0},d[101]={0};
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
             scanf("%d%d",&d[i],&p[i]),d[i]+=d[i-1];
         int f[101];
         for(int i=0;i<=n;i++) f[i]=INF;
         f[0]=0;
         for(int i=1;i<=n;i++)
             for(int j=0;j<i;j++)
                if(f[i]>f[j]+(d[i]-d[j]+10)*p[i])
                    f[i]=f[j]+(d[i]-d[j]+10)*p[i];
         printf("%d\n",f[n]);
    }
}
