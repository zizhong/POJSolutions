#include<stdio.h>
#include<stdlib.h>
const int N=101;
const int inf=99999999;
int abs1(int a)
{
    return a>0?a:-a;
}
int g[N][N],t[N][2];
int a[N][3];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
       if(i!=j) g[i][j]=inf;
    for(int i=1;i<=n;i++)
    {
         scanf("%d%d",&t[i][0],&t[i][1]);
         int x;
         scanf("%d",&x);
         while(x--)
         {
             int j;
             int y;
             scanf("%d%d",&j,&y);
             g[i][j]=y;
         }
    }
    for(int i=1;i<=n;i++)
        if(abs1(t[1][1]-t[i][1])>m)
        for(int j=1;j<=n;j++)
          if(i!=j) g[j][i]=inf;
    for(int i=1;i<=n;i++)
    {
        a[i][0]=g[1][i];
        a[i][1]=1;
    }
    a[1][2]=1;
    while(1)
    {
            int min=inf,tail;
            for(int i=1;i<=n;i++)
               if(a[i][2]==0&&a[i][0]<min)
               {
                  min=a[i][0];
                  tail=i;
               }
            if(min==inf) break;
            a[tail][2]=1;
            for(int i=1;i<=n;i++)
               if(a[i][2]==0&&a[tail][0]+g[tail][i]<a[i][0])
               {
                    a[i][0]=a[tail][0]+g[tail][i];
                    a[i][1]=tail;
               }
    }
    int min=inf;
    for(int i=1;i<=n;i++)
       if(a[i][2]&&min>t[i][0]+a[i][0])
         min=t[i][0]+a[i][0];
    printf("%d\n",min);
    //system("pause");
}
