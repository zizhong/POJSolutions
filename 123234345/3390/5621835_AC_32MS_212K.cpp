#include<stdio.h>
const int MAXN=99999999;
int a[10001],f[10001];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++)
           scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
             f[i]=MAXN;
        for(int i=1;i<=n;i++)
        {
           int j=i,sum=0;
           while(j>0&&a[j]+sum<=m)
           {
               sum+=a[j];
               --j;
               if(f[j]+(m-sum)*(m-sum)<f[i])
                f[i]=f[j]+(m-sum)*(m-sum);
                sum++;
           }
        }
        printf("%d\n",f[n]);
    }
}
