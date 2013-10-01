#include<stdio.h>
int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r),n)
    {
          int d[51][2];
          for(int i=1;i<=n;i++) d[i][0]=n+1-i;
          for(int i=1;i<=r;i++)
          {
               int p,c;
               scanf("%d%d",&p,&c);
               int cur=i&1,pre=cur^1;
               for(int j=1;j<=c;j++) d[j][cur]=d[p-1+j][pre];
               for(int j=c+1;j<=c+p-1;j++) d[j][cur]=d[j-c][pre];
               for(int j=c+p;j<=n;j++) d[j][cur]=d[j][pre];
          }
          printf("%d\n",d[1][r&1]);
    }
}
