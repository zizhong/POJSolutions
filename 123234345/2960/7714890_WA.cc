#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int N=10001;
int f[N];
int d[101],k,n;
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int SG(int x)
{
    if(f[x]!=-1) return f[x];
    if(x<d[0]) return 0;
    int ans=0;
    int v[102]={0};
    for(int i=0;i<k&&x>=d[i];i++)
            if(SG(x-d[i])<101) v[SG(x-d[i])]=1;
    while(v[ans]) ans++;
    f[x]=ans;
    return ans;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d",&k),k)
    {
         memset(f,-1,sizeof(f));
         for(int i=0;i<k;i++)
            scanf("%d",&d[i]);
         int T;
         scanf("%d",&T);
         while(T--)
         {
             int ans=0,x;
             scanf("%d",&n);
             for(int i=0;i<n;i++)
             {
                  scanf("%d",&x);
                  ans^=SG(x);
             }
             putchar(ans?'W':'L');
         }
         puts("");
    }
}
