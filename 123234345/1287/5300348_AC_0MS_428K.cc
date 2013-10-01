#include<stdio.h>
#define NIL 999
int main()
{
    int n,m;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        short v[51][51]={0};
        int a[3][51]={0};
        int i,j,k,tail,min;
        for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
            if(i!=j) v[i][j]=NIL;
        for(i=1;i<=m;i++)
        {
            int t;
            scanf("%d%d",&j,&k);
            scanf("%d",&t);
            if(v[k][j]>t) v[k][j]=t;
            if(v[j][k]>t) v[j][k]=t;
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
        int sum=0;
        for(i=2;i<=n;i++)   sum+=a[0][i];
        printf("%d\n",sum);
    }
}
