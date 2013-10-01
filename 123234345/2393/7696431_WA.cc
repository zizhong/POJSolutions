#include<stdio.h>
const int N=10001;
int c[N],y[N];
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    for(int i=1;i<=n;i++)
    {
         scanf("%d%d",&c[i],&y[i]);
    }
    int num=0,ans=0;
    for(int i=n;i>=2;i--)
    {
         num+=y[i];
         if(s+c[i-1]<c[i]) ans+=num*s;
         else ans+=num*c[i],num=0;
    }
    ans+=(num+c[1])*y[1];
    printf("%d\n",ans);
}
