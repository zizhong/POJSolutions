#include<stdio.h>
int main()
{
    int n,m,c;
    int T=0;
    while(scanf("%d%d%d",&n,&m,&c),n+m+c)
    {
         int max=0,cur=0;
         int v[21]={0},s[21]={0};
         for(int i=1;i<=n;i++)
             scanf("%d",&v[i]);
         for(int i=0;i<m;i++)
         {
             int k;
             scanf("%d",&k);
             s[k]++;
             if(s[k]&1) cur+=v[k];
             else cur-=v[k];
             if(cur>max) max=cur;
         }
         printf("Sequence %d\n",++T);
         if(max>c) printf("Fuse was blown.\n\n");
         else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n",max);
    }
}
