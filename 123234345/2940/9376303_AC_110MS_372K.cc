#include<cstdio>
#include<cstring>
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         __int64 ans=0,x,sum=0;
         for(int i=0;i<n;i++)
         {
               scanf("%I64d",&x);
               sum+=x;
               ans+=sum>0?sum:-sum;
         }
         printf("%I64d\n",ans);
    }
}
