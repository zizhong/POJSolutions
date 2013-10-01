#include<stdio.h>
int main()
{
    int n,p;
    int T=0;
    while(scanf("%d%d",&p,&n),n&&p)
    {
         int z[32]={0};
         int x=n,nn=0;
         while(x)
         {
             z[nn++]=x%p;
             x/=p;
         }
         int ans=1;
         for(int i=0;i<nn;i++)
            ans*=(z[i]+1);
            //printf("%d ",z[i]);
         //puts("");
         printf("Case %d: %04d\n",++T,ans%10000);
    }
    
}
