#include<stdio.h>
const int N=1002,P=10002;
int n,p;
short pair[P][2],mark[N],num[N];
int main()
{
    scanf("%d%d",&n,&p);
    for(int i=0;i<p;i++) scanf("%d%d",&pair[i][0],&pair[i][1]);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
         for(int j=1;j<=n;j++)
         {
                 num[j]=(i+j)%n;
                 if(!num[j]) num[j]=n;
         }
         for(int j=0;j<p;j++)
         {
                 int h1=num[pair[j][0]],h2=num[pair[j][1]];
                 if(h2<h1) {int t=h2;h2=h1;h1=t;}
                 for(int k=h1;k<h2;k++) mark[k]=i;
         }
         int min=0;
         for(int j=1;j<=n;j++) if(mark[j]==i)
                 min++;
         if(ans>min) ans=min;
    }
    printf("%d\n",ans);
}
