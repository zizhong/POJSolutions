#include<stdio.h>
#define NIL 99999999
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int v[101][101]={0};
        int a[3][101]={0};
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
        int sum=0;
        for(i=2;i<=n;i++)
           sum+=a[0][i];
        printf("%d\n",sum);
    }
}
