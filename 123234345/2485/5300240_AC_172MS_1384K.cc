#include<stdio.h>
#define NIL 99999999
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int v[501][501]={0};
        int a[3][501]={0};
        int i,j,tail,min;
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            scanf("%d",&v[i][j]);
        a[0][1]=0;
        a[2][1]=1;
        for(i=1;i<=n;i++)
        {
           a[0][i]=v[1][i];
           a[1][i]=1;
        }
        while(1)
        {
             min=NIL;
             for(i=1;i<=n;i++)
                if(a[2][i]==0&&a[0][i]<min)
                {
                    min=a[0][i];
                    tail=i;
                }
             if(min==NIL) break;
             a[2][tail]=1;
             for(i=1;i<=n;i++)
                if(a[2][i]==0&&a[0][i]>v[tail][i])
                {
                   a[0][i]=v[tail][i];
                   a[1][i]=tail;
                }
        }
        int max=0;
        for(i=2;i<=n;i++)
           if(max<a[0][i]) max=a[0][i];
        printf("%d\n",max);
    }
}
