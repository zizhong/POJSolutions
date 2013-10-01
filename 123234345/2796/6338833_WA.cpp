#include<stdio.h>
const int N=100010;
int main()
{
    int n;
    scanf("%d",&n);
    {
         int st[N],top=0,h[N],left[N],right[N],mi,sum[N];
         __int64 t,ans=-1;
         h[0]=-1,h[n+1]=-1;
         st[++top]=0;
         for(int i=1;i<=n;i++) scanf("%d",&h[i]);
         sum[0]=0;
         for(int i=1;i<=n;i++) sum[i]=sum[i-1]+h[i];
         for(int i=1;i<=n;i++)
         {
                 while(h[st[top]]>=h[i]) top--;
                 left[i]=st[top];
                 st[++top]=i;
         }
         top=1,st[1]=n+1;
         for(int i=n;i>=1;i--)
         {
                 while(h[st[top]]>=h[i]) top--;
                 right[i]=st[top];
                 st[++top]=i;
                 t=(sum[right[i]-1]-sum[left[i]])*(__int64)(h[i]);
                 if(ans<t) ans=t,mi=i;
         }
         printf("%I64d\n%d %d\n",ans,left[mi]+1,right[mi]-1);
    }
}
