#include<stdio.h>
#include<cstring>
const int N=15001;
int num[N],cnt[N];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]),cnt[i]=(num[i]+cnt[i-1])%n;
    int v[N];
    memset(v,-1,sizeof(v));
    for(int i=0;i<=n;i++)
    {
         if(v[cnt[i]]!=-1)
         {
               printf("%d\n",i-v[cnt[i]]);
               for(int j=v[cnt[i]]+1;j<=i;j++) printf("%d\n",num[j]);
               break;
         } else v[cnt[i]]=i;
    }
}
