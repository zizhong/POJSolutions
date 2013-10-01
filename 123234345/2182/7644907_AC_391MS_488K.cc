#include<stdio.h>
const int N=8001;
int d[N],cal[N],v[N];
int main()
{
    int n,i,j,t;
    scanf("%d",&n);
    for(i=2;i<=n;i++) scanf("%d",&d[i]);
    for(i=n;i>=2;i--)
    {
        t=d[i]+1;
        for(j=1;j<=n;j++) if(v[j]==0)
        {
             t--;
             if(t==0)
             {
                  v[j]=1;
                  cal[i]=j;
                  break;
             }
        }
    }
    for(i=1;i<=n;i++) if(v[i]==0)
    {
        cal[1]=i;
        break;
    }
    for(i=1;i<=n;i++) printf("%d\n",cal[i]);
    //scanf("%'d");
}
