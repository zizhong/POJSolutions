#include<stdio.h>
const int N=100010;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         int st[N],top=0,h[N],left[N],right;
         __int64 t,ans=0;
         h[0]=-1,h[n+1]=-1;
         st[++top]=0;
         for(int i=1;i<=n;i++) scanf("%d",&h[i]);
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
                 right=st[top];
                 st[++top]=i;
                 t=(right-left[i]-1)*h[i];
                 if(ans<t) ans=t;
         }
         printf("%I64d\n",ans);
    }
}
