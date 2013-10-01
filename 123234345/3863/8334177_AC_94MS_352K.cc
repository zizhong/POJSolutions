#include<stdio.h>
const int N=1000010,M=2010,inf=1000000010;
int main()
{
    
    int n,m;
    int res=inf;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
         int u,d;
         scanf("%d%d",&u,&d);
         double x=(d*n)/(u+d+0.0);
         int r1=(int)x;
         int ans=inf;
         int tmp=r1*(u+d)-d*n;
         if(tmp>0&&tmp<ans) ans=tmp;
         r1++;
         tmp=r1*(u+d)-d*n;
         if(tmp>0&&tmp<ans) ans=tmp;
         r1++;
         tmp=r1*(u+d)-d*n;
         if(tmp>0&&tmp<ans) ans=tmp;
         if(ans<res) res=ans;
    }
    printf("%d\n",res);
}
