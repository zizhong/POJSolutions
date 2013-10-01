#include<stdio.h>
const int N=10001;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
         int n;
         int a[N],b[N];
         scanf("%d",&n);
         for(int i=1;i<=n;i++)
         {
             scanf("%d",&a[i]);
             b[a[i]]=i;
         }
         int ans=0;
         for(int i=1;i<=n;i++) if(a[i]!=i)
         {
               a[b[i]]=a[i];
               b[a[i]]=b[i];
               ans++;
               
         }
         printf("%d\n",ans);
    }
}
