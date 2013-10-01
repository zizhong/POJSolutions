#include <stdio.h>
#define INF (1<<30)
int f[201010];
int main()
{
    int n,i,j,a,b;

    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<=201010;i++)
             f[i]=-INF;
           f[100000]=0;

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);

            if(a<0&&b<0)continue;

            if(a>0)
            for(j=200000;j>=a;j--)
            {
                if(f[j-a]!=-INF&&f[j-a]+b>f[j])
                   f[j]=f[j-a]+b;
            }
            else
            for(j=a;j<=200000+a;j++)
            {
                if(f[j-a]!=-INF&&f[j-a]+b>f[j])
                   f[j]=f[j-a]+b;
            }

        }
        int max=-INF;
        for(i=100000;i<=200000;i++)
          {
              if(f[i]>=0&&max<f[i]+i-100000)
                     max=f[i]+i-100000;
          }
        printf("%d\n",(max==INF)?0:max);
    }
    }