#include<stdio.h>
#define NIL 19999
short v[1001][1001];
short a[3][1001];
int n,m;
int main()
{
        int i,j,tail,min,k;
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            if(i!=j) v[i][j]=NIL;
        for(i=1;i<=m;i++)
        {
        scanf("%d%d",&j,&k);
        scanf("%d",&v[j][k]);
        v[k][j]=v[j][k];
        }
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
           if(a[0][i]!=NIL&&max<a[0][i]) max=a[0][i];
        printf("%d\n%d\n",max,n-1);
        for(i=2;i<=n;i++)
           printf("%d %d\n",a[1][i],i);}
